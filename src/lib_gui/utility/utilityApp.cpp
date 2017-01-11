#include "utility/utilityApp.h"

#include <QProcess>
#include <qprocessordetection.h>

#include "utility/utilityString.h"

std::string utility::executeProcess(const char *cmd)
{
	QProcess process;
	process.setProcessChannelMode(QProcess::MergedChannels);
	process.start(cmd);
	process.waitForFinished();
	std::string processoutput = process.readAll().toStdString();
	process.close();
	processoutput = utility::trim(processoutput);

	return processoutput;
}

ApplicationArchitectureType utility::getApplicationArchitectureType()
{
#ifdef Q_PROCESSOR_X86_64
	return APPLICATION_ARCHITECTURE_X86_64;
#endif

#ifdef Q_PROCESSOR_X86_32
	return APPLICATION_ARCHITECTURE_X86_32;
#endif
	return APPLICATION_ARCHITECTURE_UNKNOWN;
}
