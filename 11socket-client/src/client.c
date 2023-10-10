#include <arpa/inet.h>
#include <asm/byteorder.h>
#include <cygwin/in.h>
#include <cygwin/socket.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/unistd.h>

#define SERVER_PORT 6666
/*
 ���ӵ��������󣬻᲻ͣѭ�����ȴ����룬
 ����quit�󣬶Ͽ��������������
 */
int main() {
  //�ͻ����׽����ļ�������
  int client_socket;
  //������������socket,������ַ����,IP,�˿�
  struct sockaddr_in server_addr;
  char sendbuf[1024*1024];
  char recvbuf[1024*1024];
  int date_size;

  //����socket,�����ļ�������
  if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return 1;
  }

  //��ʼ������˵ص�ַ
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  //���ӷ���˿ڶ˿ڻ�ȡsocket,����ȡ��socket��client_socket��
  if (connect(client_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return 1;
  }

  printf("���ӵ�����...\n");
  while (1) {
    printf("������Ϣ:");
    //��ȡ���뵽senbuf
    scanf("%s", sendbuf);
    printf("\n");
    //���ݵ�client���ļ�������
    send(client_socket, sendbuf, strlen(sendbuf), 0);
    if (strcmp(sendbuf, "quit") == 0)
      break;
    printf("��ȡ��Ϣ:");
    recvbuf[0] = '\0';
    date_size = recv(client_socket, recvbuf, 1024*1024, 0);
    recvbuf[date_size] = '\0';
    printf("%s\n", recvbuf);
  }
  close(client_socket);
  return 0;
}
