#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<assert.h>
#include <iostream>
#include <string>

using namespace std;
int client_fd;
int numbytes;
char buff[100];
char response[] = "HTTP/1.1 200 OK\r\n"
"Content-Type: text/html; charset=UTF-8\r\n\r\n"
"<!DOCTYPE html>"
"<html lang=\"zh-CN\">"
"<head>"
"<meta charset=\"utf-8\">"
"<title>Hello World</title>"
"<style>body {width: 35em;margin: 200px auto;font-family: Tahoma, Verdana, Arial, sans-serif;}"
"</style>"
"</head>"
"<body>"
"<p>This is a simple webserver<p>"
"<p><em>And this html does not support ZH-CN</em></p>"
"</body></html>\r\n";


char r[] = "HTTP/1.1 200 OK\r\n""Content-Type: text/html; charset=UTF-8\r\n\r\n""<!DOCTYPE html><html><head><meta charset='utf-8'><</head><body>    <h1>yyy</h1>    <p>111</p></body></html>";

void solve()
{
	char data[1000];
	char cd[500];
	char args[500];
	strcpy(args, "./");
	if (sscanf(buff, "%s%s", cd, args + 2) != 2)
	{
		return;
	}
	//  cout<<" 111 "<<cd<<endl;
	//  cout<<" 111 "<<args<<endl;
	if (strcmp(cd, "GET") != 0)
	{
		cout << "�������ʹ���" << endl;
		return;
	}
	// int fd = open(args,O_RDONLY);
	// int x = send(client_fd,response, sizeof(response)-1,0);
	//    send(client_fd,fd,NULL,2500);
	string s;
	char str[100];
	cout << args << endl;
	if (!strcmp(args, ".//index.html"))
	{
		FILE * fp;
		if ((fp = fopen(args, "rt")) == NULL)
		{
			//  cout<<"����"<<endl;
		}
		else
		{
			//    cout<<"��"<<endl;
			while ((fgets(str, 1024, fp)) != NULL)
			{
				s += str;
				cout << s << endl;
			}
			//  cout<<"��giao"<<endl;
		}
		fclose(fp);
		cout << s << endl;
		// cout<<response<<endl;
		cout << send(client_fd, r, sizeof(r), 0) << "Bytes�ѷ���" << endl;
	}
	else {
		cout << response << endl;
		cout << send(client_fd, response, sizeof(response), 0) << "Bytes�ѷ���" << endl;
	}
	//  FILE * fp = open(args,O_RDONLY);

	// cout<< pBuf <<endl;
	return;
}
int main()
{
	char recbuf[2048];
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKADDR_IN svr_addr, cli_addr;
	int sin_len = sizeof(cli_addr);

	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
	{
		cout << "�޷�����socket";
		exit(0);
	}

	int port = 81;
	svr_addr.sin_family = AF_INET;
	svr_addr.sin_addr.s_addr = INADDR_ANY;
	svr_addr.sin_port = htons(port);

	if (bind(sock, (SOCKADDR *)&svr_addr, sizeof(svr_addr)) == -1)
	{
		closesocket(sock);
		cout << "�޷���\n";
	}

	listen(sock, 5);
	while (1)
	{
		int len = sizeof(SOCKADDR);
		client_fd = accept(sock, (SOCKADDR *)&cli_addr, &sin_len);
		printf("�ͻ���������\n");
		//cout << inet_ntoa(cli_addr.sin_addr) << endl;
		if (client_fd == -1)
		{
			perror("accept()�ͻ������ӳ���");
			continue;
		}
		if ((numbytes = recv(client_fd, buff, 99, 0)) == -1)
		{
			perror("recv");
			exit(1);
		}
		cout << buff << endl;

		solve();

		// cout<<response<<endl;
	}
	closesocket(client_fd);
	WSACleanup();
}
