// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "pch.h"
#include "Winsock.h"
#include "stdafx.h"
#include "asio.hpp"
#include "windows.h"
#include "iostream"
#include "string"

#include "shellapi.h"


using namespace asio;




int main()
{
	double i = 0.0;

	while (true) {
		i++;
		io_service io_service;
		ip::udp::socket socket(io_service);
		ip::udp::endpoint remote_endpoint;

		socket.open(ip::udp::v4());

		remote_endpoint = ip::udp::endpoint(ip::address::from_string("127.0.0.1"), 777);


		std::string out = std::to_string(i);


		socket.send_to(buffer(out, 3), remote_endpoint, 0);

		socket.close();

		printf("sent");

		Sleep(500);

	}

    return 0;
}

