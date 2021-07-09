#include "./LocalRendDriver.h"

void XYY_LocalRendDriver::run()
{
	update();
	draw();
}

//����ģ��
/* 
void XYY_LocalRendDriver::load_model(std::string const& modelpath)
{
	this->model = new Model(modelpath);
}
 */
void XYY_LocalRendDriver::draw()
{
	if (type == 2) skybox->draw(shader);
	else if (type == 1) cube->draw(shader);
	else model->draw(*shader);
}
void XYY_LocalRendDriver::update()
{
	//std::cout << "object update" << std::endl;
	shader->use();
	shader->setVec3("objectcolor", color);
	shader->setMat4("model", modelmat);
	shader->setMat4("view", viewmat);
	shader->setMat4("projection", projectionmat);
}

void XYY_LocalRendDriver::move(glm::vec3 translation)
{
	position += translation;
	modelmat = glm::translate(modelmat, translation);
	update();
}
void XYY_LocalRendDriver::Stretch(glm::vec3 scale)
{
	this->scale *= scale;
	modelmat = glm::scale(modelmat, scale);
	update();
}
void XYY_LocalRendDriver::spin(float angle, glm::vec3 rotation)
{
	//��ʱ������Ԫ�����պ���ʱ�佫���е������Ϊ��Ԫ����ʾ������ʹ��ŷ���ǻ���BUG;
	modelmat = glm::rotate(modelmat, glm::radians(angle), rotation);
	update();
}
void XYY_LocalRendDriver::setposition(glm::vec3 position)
{
	move(position - this->position);
}