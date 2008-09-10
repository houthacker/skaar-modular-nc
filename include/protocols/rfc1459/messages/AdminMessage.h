/**
 * @file AdminMessage.h
 * @brief Implementation for the ADMIN message of RFC1459
 *
 * Copyright (c) 2008 Coen Bijlsma
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ADMINMESSAGE_H
#define ADMINMESSAGE_H

#include <string>
#include <vector>
#include "SkaarUser.h"
#include "RFC1459.h"

using namespace std;

class AdminMessage : public AbstractMessage {
private:
	RFC1459* _protocol;
	string _raw;
	string _prefix;
	vector<string> _params;
	SkaarUser* _user;
	
	void _init();

public:
	static const string COMMAND = "ADMIN";
	static const unsigned int MINPARAMS = 0;
	
	AdminMessage(RFC1459* protocol, string raw);
	~AdminMessage();
	
	string getPrefix();
	string getSenderNick();
	string getReceiver();
	string getCommand();
	unsigned int getMinParams();
	
	/**/
	string format(string format);
	vector<string> getParams();
	
	RFC1459* getProtocol();
};

#endif
