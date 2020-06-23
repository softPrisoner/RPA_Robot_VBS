#include "robot_vbs.h"

void RobotVbs::message(const string msg) {
	//脚本执行文件
	fstream out("Rpa.vbs", ios::out);
	string okmsg_prefix = "Set WshShell=WScript.CreateObject(\"WScript.Shell\")\n\
			WScript.Sleep 500\n\
			WshShell.SendKeys\"";

	if (msg.empty()) {
		printf("发送失败");
		return;
	}

	string okmsg_suffix = "\"\n\
			WshShell.SendKeys\"{ }\"\n\
			WScript.Sleep 100\n\
			WshShell.SendKeys\"{ENTER}\"\n\
			";
	string send_msg = okmsg_prefix.append(msg).append(okmsg_suffix);

	out << send_msg;

	out.close();
	system("Rpa.vbs");
	system("del Rpa.vbs");
}