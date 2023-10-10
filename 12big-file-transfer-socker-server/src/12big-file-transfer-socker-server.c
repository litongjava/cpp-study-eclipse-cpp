#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_PORT                6666
#define LENGTH_OF_LISTEN_QUEUE     20
#define BUFFER_SIZE                1024
#define FILE_NAME_MAX_SIZE         512

int main(int argc, char **argv) {
  // ����һ��socket��ַ�ṹserver_addr,���������internet�ĵ�ַ�Ͷ˿�
  struct sockaddr_in server_addr;
  bzero(&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htons(INADDR_ANY);
  server_addr.sin_port = htons(SERVER_PORT);

  // ��������internet����Э��(TCP)socket����server_socket�����������ͻ����ṩ����Ľӿ�
  int server_socket = socket(PF_INET, SOCK_STREAM, 0);
  if (server_socket < 0) {
    printf("Create Socket Failed!\n");
    exit(1);
  }

  // ��socket��socket��ַ�ṹ��
  int ret=bind(server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr));
  printf("ret:%i",ret);
  if (ret) {
    printf("Server Bind Port: %d Failed!\n", SERVER_PORT);
    exit(1);
  }

  // server_socket���ڼ���
  if (listen(server_socket, LENGTH_OF_LISTEN_QUEUE)) {
    printf("Server Listen Failed!\n");
    exit(1);
  }

  // ��������һֱ�������Գ���Ϊ�ͻ����ṩ����
  while (1) {
    // ����ͻ��˵�socket��ַ�ṹclient_addr�����յ����Կͻ��˵������
    // ����accept���ܴ�����ͬʱ��client�˵ĵ�ַ�Ͷ˿ڵ���Ϣд��client_addr��
    struct sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);

    // ����һ����client�˵���server�˵���������,���ͻ��˵���Ϣ������client_addr��
    // ���û������������һֱ�ȴ�ֱ������������Ϊֹ������accept���������ԣ�������select()��ʵ�ֳ�ʱ���
    // accpet����һ���µ�socket,���socket������˴����ӵ�server��client����ͨ��
    // �����client_socket���������ͨ��ͨ��socket���ļ�������
    int client_socket = accept(server_socket, (struct sockaddr*) &client_addr, &length);
    if (client_socket < 0) {
      printf("Server Accept Failed!\n");
      break;
    }

    char buffer[BUFFER_SIZE];
    bzero(buffer, sizeof(buffer));
    length = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (length < 0) {
      printf("Server Recieve Data Failed!\n");
      break;
    }

    char file_name[FILE_NAME_MAX_SIZE + 1];
    bzero(file_name, sizeof(file_name));
    length = strlen(buffer) > FILE_NAME_MAX_SIZE ? FILE_NAME_MAX_SIZE : strlen(buffer);
    strncpy(file_name, buffer, length);

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
      printf("File:\t%s Not Found!\n", file_name);
    } else {
      bzero(buffer, BUFFER_SIZE);
      int file_block_length = 0;
      while ((file_block_length = fread(buffer, sizeof(char), BUFFER_SIZE, fp)) > 0) {
        printf("file_block_length = %d\n", file_block_length);

        // ����buffer�е��ַ�����new_server_socket,ʵ���Ͼ��Ƿ��͸��ͻ���
        if (send(client_socket, buffer, file_block_length, 0) < 0) {
          printf("Send File:\t%s Failed!\n", file_name);
          break;
        }

        bzero(buffer, sizeof(buffer));
      }
      fclose(fp);
      printf("File:\t%s Transfer Finished!\n", file_name);
    }

    close(client_socket);
  }
  close(server_socket);
  return 0;
}
