#include <arpa/inet.h>
#include <asm/byteorder.h>
#include <cygwin/in.h>
#include <cygwin/socket.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/unistd.h>

#define SERVER_PORT 6666
/*
 ������һֱ����accept����״̬��
 ֱ���пͻ������ӣ�
 ���ͻ�������quit�󣬶Ͽ���ͻ��˵�����
 */
int main() {
  //����socket���ص��ļ�������
  int server_socket;
  //����accpet���ص��ļ�������
  int client_socket;
  //���������׽���sockaddr_in�ṹ��������ֱ��ʾ�ͻ��˺ͷ�����
  struct sockaddr_in server_addr;
  struct sockaddr_in client_addr;
  int addr_len = sizeof(client_addr);

  char buffer[1024*1024];
  int data_size;

  //����socket,�����ļ�������
  if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return 1;
  }

  //���server_addr
  bzero(&server_addr, sizeof(server_addr));
  //��ʼ���������˵��׽��֣�����htons��htonl���˿ں͵�ַת�������ֽ���
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  //ip�����Ǳ���������ip��Ҳ�����ú�INADDR_ANY���棬����0.0.0.0���������е�ַ
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  //��socket�ļ���������socket��
  if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    return 1;
  }

  //���÷������ϵ�socketΪ����״̬
  if (listen(server_socket, 5) < 0) {
    perror("listen");
    return 1;
  }
  while (1) {
    printf("�����˿�: %d\n", SERVER_PORT);
    //���ܷ��͵�server_socket�е�����,�����󷽵�ip�Ͷ˿�д�뵽client_addr,�����ؽ������ݵ��ļ�������
    client_socket = accept(server_socket, (struct sockaddr*) &client_addr, (socklen_t*) &addr_len);
    if (client_socket < 0) {
      perror("accept");
      continue;
    }
    printf("�ȴ���Ϣ...\n");

    printf("peer ip   : %s\n", inet_ntoa(client_addr.sin_addr));
    printf("peer port : %d\n", htons(client_addr.sin_port));
    while (1) {
      printf("��ȡ��Ϣ:");
      buffer[0] = '\0';
      data_size = recv(client_socket, buffer, 1024*1024, 0);
      if (data_size < 0) {
        perror("recv null");
        continue;
      }
      buffer[data_size] = '\0';
      if (strcmp(buffer, "quit") == 0)
        break;
      printf("%s\n", buffer);

      printf("������Ϣ:");
      scanf("%s", buffer);
      printf("\n");
      send(client_socket, buffer, strlen(buffer), 0);
      if (strcmp(buffer, "quit") == 0)
        break;
    }
  }
  close(server_socket);
  return 0;
}
