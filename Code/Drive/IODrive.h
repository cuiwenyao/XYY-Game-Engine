#ifndef IODRIVE_H
#define IODRIVE_H
#include "../Element/Element.h"

//�����������룬�����������С�
class IODrive
{
public:
	void IO(Element* element);
private:
	void keyInput(Element* element);
	void mouseInput(Element* element);
	void scrollInput(Element* element);
};


#endif