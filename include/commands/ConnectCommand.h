#ifndef CONNECTCOMMAND_H
#define CONNECTCOMMAND_H

#include <string>
#include "AbstractCommand.h"
#include "CommandHandler.h"
#include "SkaarLog.h"

using namespace std;

/*
 * Syntax: /connect <server> [<port> [proto=rfc1459]]
 * port and protocol are only optional if the server is
 * defined in the config-file
 */
class ConnectCommand : public AbstractCommand {
private:
	CommandHandler* _handler;
	SkaarLog* _log;
	string _command;
	string _raw;
	string _server;
	int _port;
	string _proto;
	
public:
	static const string COMMAND;
	static const int MINPARAMS = 1;
	static const int MAXPARAMS = 3;
	
	ConnectCommand(string raw);
	~ConnectCommand();
	
	string getCommand();
	
	void setCommandHandler(CommandHandler* handler);
	
	bool execute();
};

#endif /* CONNECTCOMMAND_H */
