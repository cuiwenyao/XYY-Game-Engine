#include "./SceneContent.h"

XYY_SceneContent::XYY_SceneContent()
{
	skybox = NULL;
	return;
}
/*
XML��������ģ�������
	1����Դ����
	2���������Ƶ����Ա༭
	3��base ����Ǩ��
	4��ɾ���� �������
*/
bool XYY_SceneContent::loadXML(const char * path)
{
	// XML�ĵ�
	TiXmlDocument doc;
	// ����XML�ĵ�
	if (!doc.LoadFile(path)) { std::cerr << doc.ErrorDesc() << std::endl; return false; }

	// ������ڵ��������ֵΪ�ĵ��ĵ�һ�����ڵ�
	TiXmlElement * root = doc.FirstChildElement();
	// ���û���ҵ����ڵ�,˵���� ��XML�ĵ� ���� ��XML�ĵ�
	if (root == NULL)
	{
		std::cerr << "Failed to load file: No root element." << std::endl;
		// �����ڴ�
		doc.Clear();
		return false;
	}

	// ����Ĭ�� shader
	XYY_ShaderResource * defaultobjectshader = new XYY_ShaderResource("GLSL/object.vert", "GLSL/object.frag");
	XYY_ShaderResource * defaultskyboxshader = new XYY_ShaderResource("GLSL/skybox.vert", "GLSL/skybox.frag");
	// ��Դ����
	std::map<std::string, XYY_ModelResource *> ModelMap;		// ģ�͸���
	std::map<std::string, XYY_TextureResource *> TextureMap;	// ������
	std::map<std::string, XYY_ShaderResource *> ShaderMap;		// Shader���ã���δʵ��

	// �����ӽڵ�
	for (TiXmlElement *elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
	{
		// ��ȡԪ����
		std::string elemName = elem->Value();
	//	std::cout << elemName << std::endl;
		if (elemName == "objects")
		{
			for (TiXmlElement * sonele = elem->FirstChildElement(); sonele != NULL; sonele = sonele->NextSiblingElement())
			{
				std::string sonelenName = sonele->Value(); //std::cout << " " << sonelenName << std::endl;
				if (sonelenName == "model")
				{
					// path id
					std::string path; bool _path = false;
					std::string id;  bool _id = false;
					if (sonele->Attribute("path")) _path = true, path = sonele->Attribute("path");
					if (sonele->Attribute("id")) _id = true, id = sonele->Attribute("id");
					if (!_id || !_path) continue;
					ModelMap[id] = new XYY_ModelResource(path);
				}
				else if (sonelenName == "object")
				{
					// modelpath vert frag modelid
					std::string modelpath; bool _modelpath = false;
					std::string vertpath, fragpath; bool vert = false, frag = false;
					std::string modelid; bool _modelid = false;
					if (sonele->Attribute("modelpath")) _modelpath = true, modelpath = sonele->Attribute("modelpath");// std::cout << "  " << "modelpath:" << sonele->Attribute("modelpath") << std::endl;
					if (sonele->Attribute("vert")) vert = true, vertpath = sonele->Attribute("vert");//  std::cout << "  " << "vert:" << sonele->Attribute("vert") << std::endl;
					if (sonele->Attribute("frag")) frag = true, fragpath = sonele->Attribute("frag");// std::cout << "  " << "frag:" << sonele->Attribute("frag") << std::endl;
					if (sonele->Attribute("modelid")) _modelid = true, modelid = sonele->Attribute("modelid");
					if (!_modelpath && !_modelid) continue;
					XYY_ShaderResource * shader = defaultobjectshader;
					if (vert && frag) shader = new XYY_ShaderResource(vertpath.c_str(),fragpath.c_str());
					XYY_ObjectElement * obj;
					if (_modelpath) obj = new XYY_ObjectElement(modelpath, defaultobjectshader);
					else obj = new XYY_ObjectElement(ModelMap[modelid], defaultobjectshader);

					// colorr colorg colorb
					std::string colorr = "0"; bool _colorr = false;
					std::string colorg = "0"; bool _colorg = false;
					std::string colorb = "0"; bool _colorb = false;
					if (sonele->Attribute("colorr")) _colorr = true, colorr = sonele->Attribute("colorr");
					if (sonele->Attribute("colorg")) _colorg = true, colorg = sonele->Attribute("colorg");
					if (sonele->Attribute("colorb")) _colorb = true, colorb = sonele->Attribute("colorb");
					if (_colorr || _colorg || _colorb)
					{
						obj->ld_rend->color = glm::vec3(atof(colorr.c_str()), atof(colorg.c_str()), atof(colorb.c_str()));
					}

					// positionx positiony positionz
					std::string posx = "0"; bool px = false;
					std::string posy = "0"; bool py = false;
					std::string posz = "0"; bool pz = false;
					if (sonele->Attribute("positionx")) px = true, posx = sonele->Attribute("positionx");// std::cout << "  " << "positionx:" << sonele->Attribute("positionx") << std::endl;
					if (sonele->Attribute("positiony")) py = true, posy = sonele->Attribute("positiony");// std::cout << "  " << "positiony:" << sonele->Attribute("positiony") << std::endl;
					if (sonele->Attribute("positionz")) pz = true, posz = sonele->Attribute("positionz");// std::cout << "  " << "positionz:" << sonele->Attribute("positionz") << std::endl;
					if (px || py || pz)
					{
						obj->ld_rend->move( glm::vec3( atof( posx.c_str() ) , atof(posy.c_str()) , atof(posz.c_str()) ) );
					}

					// scalex scaley scalez
					std::string scalex = "1"; bool _scalex = false;
					std::string scaley = "1"; bool _scaley = false;
					std::string scalez = "1"; bool _scalez = false;
					if (sonele->Attribute("scalex")) _scalex = true, scalex = sonele->Attribute("scalex");
					if (sonele->Attribute("scaley")) _scaley = true, scaley = sonele->Attribute("scaley");
					if (sonele->Attribute("scalez")) _scalez = true, scalez = sonele->Attribute("scalez");
					if (_scalex || _scaley || _scalez)
					{
						obj->ld_rend->Stretch(glm::vec3(atof(scalex.c_str()), atof(scaley.c_str()), atof(scalez.c_str())));
					}

					Objects.push_back(obj);
				}
				else if (sonelenName == "cube")
				{
					// vert frag 
					std::string vertpath, fragpath; bool vert = false, frag = false;
					if (sonele->Attribute("vert")) vert = true, vertpath = sonele->Attribute("vert");
					if (sonele->Attribute("frag")) frag = true, fragpath = sonele->Attribute("frag");
					XYY_ShaderResource * shader = defaultobjectshader;
					if (vert && frag) shader = new XYY_ShaderResource(vertpath.c_str(), fragpath.c_str());
					XYY_CubeElement * cube = new XYY_CubeElement(defaultobjectshader);

					// colorr colorg colorb
					std::string colorr = "0"; bool _colorr = false;
					std::string colorg = "0"; bool _colorg = false;
					std::string colorb = "0"; bool _colorb = false;
					if (sonele->Attribute("colorr")) _colorr = true, colorr = sonele->Attribute("colorr");
					if (sonele->Attribute("colorg")) _colorg = true, colorg = sonele->Attribute("colorg");
					if (sonele->Attribute("colorb")) _colorb = true, colorb = sonele->Attribute("colorb");
					if (_colorr || _colorg || _colorb )
					{
						cube->ld_rend->color = glm::vec3( atof( colorr.c_str() ) , atof(colorg.c_str()) , atof(colorb.c_str()));
					}

					// positionx positiony positionz
					std::string posx = "0"; bool px = false;
					std::string posy = "0"; bool py = false;
					std::string posz = "0"; bool pz = false;
					if (sonele->Attribute("positionx")) px = true, posx = sonele->Attribute("positionx");// std::cout << "  " << "positionx:" << sonele->Attribute("positionx") << std::endl;
					if (sonele->Attribute("positiony")) py = true, posy = sonele->Attribute("positiony");// std::cout << "  " << "positiony:" << sonele->Attribute("positiony") << std::endl;
					if (sonele->Attribute("positionz")) pz = true, posz = sonele->Attribute("positionz");// std::cout << "  " << "positionz:" << sonele->Attribute("positionz") << std::endl;
					if (px || py || pz)
					{
						cube->ld_rend->move(glm::vec3(atof(posx.c_str()), atof(posy.c_str()), atof(posz.c_str())));
					}

					// scalex scaley scalez
					std::string scalex = "1"; bool _scalex = false;
					std::string scaley = "1"; bool _scaley = false;
					std::string scalez = "1"; bool _scalez = false;
					if (sonele->Attribute("scalex")) _scalex = true, scalex = sonele->Attribute("scalex");
					if (sonele->Attribute("scaley")) _scaley = true, scaley = sonele->Attribute("scaley");
					if (sonele->Attribute("scalez")) _scalez = true, scalez = sonele->Attribute("scalez");
					if (_scalex || _scaley || _scalez)
					{
						cube->ld_rend->Stretch(glm::vec3(atof(scalex.c_str()), atof(scaley.c_str()), atof(scalez.c_str()))) ;
					}
					 
					// texture
					for (TiXmlElement * sonson = sonele->FirstChildElement(); sonson != NULL; sonson = sonson->NextSiblingElement())
					{
						std::string sonsonName = sonson->Value();
						if (sonsonName == "texture")
						{
							// type path id
							std::string texpath; bool _texpath = false;
							std::string textype; bool _textype = false;
							std::string textureid; bool _textureid = false;
							if (sonson->Attribute("type")) _textype = true, textype = sonson->Attribute("type");
							if (sonson->Attribute("path")) _texpath = true, texpath = sonson->Attribute("path");
							if (sonson->Attribute("id")) _textureid = true, textureid = sonson->Attribute("id");
							if ( !_textype ) _textype = true , textype = "ambient";
							if ( !_texpath && !_textureid ) continue;
							if (_texpath)
							{
								XYY_TextureResource * texture;
								if (textype == "ambient")texture = new XYY_TextureResource(texpath, XYY_TEXTURE_TYPE_AMBIENT);
								else if (textype == "specular") texture = new XYY_TextureResource(texpath, XYY_TEXTURE_TYPE_SPECULAR); 
								cube->addtexture( texture );
								if (_textureid) TextureMap[textureid] = texture;
							}
							else if (_textureid) cube->addtexture(TextureMap[textureid]);

						}
					}

					

					Objects.push_back(cube);
				}
			}

		}
		else if (elemName == "lights")
		{
			for (TiXmlElement * sonele = elem->FirstChildElement(); sonele != NULL; sonele = sonele->NextSiblingElement())
			{
				std::string soneleName = sonele->Value();// std::cout << " " << soneleName << std::endl;
				if (soneleName == "light")
				{
					// type positionx positiony positionz
					std::string lttype = "point"; bool type = false;
					std::string ltposx = "0"; bool posx = false;
					std::string ltposy = "0"; bool posy = false;
					std::string ltposz = "0"; bool posz = false;
					if (sonele->Attribute("type")) type = true, lttype = sonele->Attribute("type");// std::cout << "  " << "type:" << sonele->Attribute("type") << std::endl;
					if (sonele->Attribute("positionx")) posx = true, ltposx = sonele->Attribute("positionx");// std::cout << "  " << "positionx:" << sonele->Attribute("positionx") << std::endl;
					if (sonele->Attribute("positiony")) posy = true, ltposy = sonele->Attribute("positiony");// std::cout << "  " << "positiony:" << sonele->Attribute("positiony") << std::endl;
					if (sonele->Attribute("positionz")) posz = true, ltposz = sonele->Attribute("positionz");// std::cout << "  " << "positionz:" << sonele->Attribute("positionz") << std::endl;
					// if (sonele->FirstChild()) std::cout << "  " << "text:" << sonele->FirstChild()->ToText()->Value() << std::endl;
					XYY_LightElement * light;
					if (lttype == "directional") light = new XYY_LightElement(0);
					else if (lttype == "spot") light = new XYY_LightElement(2);
					else light = new XYY_LightElement(1);
					light->ld_light->position = glm::vec3(atof(ltposx.c_str()), atof(ltposy.c_str()), atof(ltposz.c_str()));


					// colorr colorg colorb
					std::string colorr = "0"; bool _colorr = false;
					std::string colorg = "0"; bool _colorg = false;
					std::string colorb = "0"; bool _colorb = false;
					if (sonele->Attribute("colorr")) _colorr = true, colorr = sonele->Attribute("colorr");
					if (sonele->Attribute("colorg")) _colorg = true, colorg = sonele->Attribute("colorg");
					if (sonele->Attribute("colorb")) _colorb = true, colorb = sonele->Attribute("colorb");
					if (_colorr || _colorg || _colorb)
					{
						light->setcolor( glm::vec3(atof(colorr.c_str()), atof(colorg.c_str()), atof(colorb.c_str())) );
					}

					Lights.push_back(light);
				}
			}
		}
		else if (elemName == "cameras")
		{
			for (TiXmlElement * sonele = elem->FirstChildElement(); sonele != NULL; sonele = sonele->NextSiblingElement())
			{
				std::string sonelenName = sonele->Value();// std::cout << " " << sonelenName << std::endl;
				if (sonelenName == "camera")
				{
					// positionx positiony positionz frontx fronty frontz
					std::string frx = "0";		 
					std::string fry = "0";
					std::string frz = "0";	
					std::string posx = "0";
					std::string posy = "0";
					std::string posz = "0";
					if (sonele->Attribute("positionx")) posx = sonele->Attribute("positionx");// std::cout << "  " << "positionx:" << sonele->Attribute("positionx") << std::endl;
					if (sonele->Attribute("positiony")) posy = sonele->Attribute("positiony");// std::cout << "  " << "positiony:" << sonele->Attribute("positiony") << std::endl;
					if (sonele->Attribute("positionz")) posz = sonele->Attribute("positionz");// std::cout << "  " << "positionz:" << sonele->Attribute("positionz") << std::endl;
					if (sonele->Attribute("frontx")) frx = sonele->Attribute("frontx");// std::cout << "  " << "frontx:" << sonele->Attribute("frontx") << std::endl;
					if (sonele->Attribute("fronty")) fry = sonele->Attribute("fronty");// std::cout << "  " << "fronty:" << sonele->Attribute("fronty") << std::endl;
					if (sonele->Attribute("frontz")) frz = sonele->Attribute("frontz");// std::cout << "  " << "frontz:" << sonele->Attribute("frontz") << std::endl;

					// if (sonele->FirstChild()) std::cout << "  " << "text:" << sonele->FirstChild()->ToText()->Value() << std::endl;

					XYY_CameraElement * cra = new XYY_CameraElement();
					cra->position = glm::vec3(atof(posx.c_str()), atof(posy.c_str()), atof(posz.c_str()));
					cra->position = glm::vec3(atof(frx.c_str()), atof(fry.c_str()), atof(frz.c_str()));
					Cameras.push_back(cra);

				}
			}
		}
		else if (elemName == "skybox")
		{
			// path
			std::string skypath; bool path = false;
			if (elem->Attribute("path")) path = true, skypath = elem->Attribute("path");// std::cout << "  " << "path:" << elem->Attribute("path") << std::endl;
			if (!path) continue;
			XYY_SkyboxElement * skybx = new XYY_SkyboxElement(skypath, defaultskyboxshader);
			skybox = skybx;
		}

	}
	// �����ڴ�
	doc.Clear();
	return true;
}

// xihang����δʵ�� �� �Ժ���Ի��ڴ� ʵ��һ�� ���ӻ��� �����༭��
bool XYY_SceneContent::saveXML(const char * path)
{
	/* 
	// XML�ĵ�
	TiXmlDocument doc;

	// ���ڵ� ( ���ڵ��������� )				
	TiXmlElement *root = new TiXmlElement("root");
	// ���ĵ��м���һ�����ڵ�
	doc.LinkEndChild(root);

	// ��һ��Ԫ��
	TiXmlElement *element1 = new TiXmlElement("Element1");
	// �ڸ��ڵ��¼�����Ԫ��
	root->LinkEndChild(element1);
	// �����Ԫ������
	element1->SetAttribute("attribute1", "some value");

	// �ڶ���Ԫ��
	TiXmlElement *element2 = new TiXmlElement("Element2");
	// �ڸ��ڵ����ٴμ���Ԫ��
	root->LinkEndChild(element2);
	// ���ø�Ԫ�ص�һ������ֵ
	element2->SetAttribute("attribute2", "2");
	// ���ø�Ԫ�صڶ�������ֵ
	element2->SetAttribute("attribute3", "3");

	// ������Ԫ��
	TiXmlElement *element3 = new TiXmlElement("Element3");
	// ע��:�����ڵڶ���Ԫ��(element2)�¼���Ԫ��(element3)
	element2->LinkEndChild(element3);
	// ���ø�Ԫ������ֵ
	element3->SetAttribute("attribute4", "4");

	// �ı�Ԫ��
	TiXmlText *text = new TiXmlText("Some text.");
	// �ڵڶ���Ԫ���¼����ı�
	element2->LinkEndChild(text);

	// �����ĵ�
	bool sucess = doc.SaveFile("b.xml");
	// �����ڴ�
	doc.Clear();

	if (sucess)
		return SUCCESS;
	else
		return FAILURE;
	*/
	return false;
}