#include"stdio.h"
#include"stdlib.h"

#include"AudioInformation.h"
#include"DecreaseVolume.h"

DecreaseVolume::DecreaseVolume()
{
	AudioInformation vol;

	volume = vol.getVolume();

	newVolume();
	updateVolume();
	updateTheCurrentVolume();
}


void DecreaseVolume::newVolume()
{
	volume = volume - AFFECTAMOUNT;
}
void DecreaseVolume::updateVolume()
{
	std::string command = "amixer -c 1 set DAC0 ";
	command.append(std::to_string(volume));
	system(command.c_str());
}
