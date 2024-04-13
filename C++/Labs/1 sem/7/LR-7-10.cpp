// LR-7-10.cpp Выполнил:Тиханёнок Илья
/*Задание 10: Патриций решил устроить праздник и для этого приготовил 240 
бочек вина. Однако к нему пробрался недоброжелатель, который подсыпал 
яд в одну из бочек. Недоброжелателя тут же поймали, дальнейшая его судьба 
неизвестна. Про яд известно, что человек, который его выпил, умирает в 
течение 24 часов. До праздника осталось два дня, то есть 48 часов. У 
патриция есть пять рабов, которыми он готов пожертвовать, чтобы узнать, в 
какой именно бочке яд. Каким образом можно это узнать?*/

#include <iostream>

int main()
{
	int time, quantity, barrel;
	std::cout << "Time of death(minutes):";
	std::cin >> time;
	std::cout << "Death slave:";
	std::cin >> quantity;
	switch (quantity)
	{
	case 1:
		time /= 30;
		barrel = time;
		std::cout << barrel;
		break;
	case 2:
		time /= 30;
		barrel = time + 48;
		std::cout << barrel;
		break;
	case 3:
		time /= 30;
		barrel = time + 96;
		std::cout << barrel;
		break;
	case 4:
		time /= 30;
		barrel = time + 144;
		std::cout << barrel;
		break;
	case 5:
		time /= 30;
		barrel = time + 192;
		std::cout << barrel;
		break;
	}
}