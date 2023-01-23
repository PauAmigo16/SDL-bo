#include "LevelLoader.h"



LevelLoader* LevelLoader::instance = nullptr;

LevelLoader* LevelLoader::GetInstance()
{
	if (instance == nullptr)
		instance = new LevelLoader();

	return instance;
}

void LevelLoader::LoadLevel(std::string path, GameplayScene* myGameplay)
{
	rapidxml::xml_document<> doc;
	std::ifstream file(path);
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	std::cout << content;
	doc.parse<0>(&content[0]);

	rapidxml::xml_node<>* pRoot = doc.first_node();

	myGameplay->maxTime = stof((std::string)pRoot->first_node("MaxTime")->value());
	//dynamic_cast<TimeBar*>(gamelay->gameUI.find("timeBar")->second)->SetMaxTime(stof((std::string)pRoot->first_node()->value()));
	pRoot = pRoot->first_node("Layout");

	myGameplay->endHazardChances = stof((std::string)pRoot->first_node()->first_attribute()->value());
	Vector2 spawnPosition(0,2);
		
	for (rapidxml::xml_node<>* pNode = pRoot->first_node(); pNode; pNode = pNode->next_sibling())
	{
		if ((std::string)pNode->name() == "EndZone")
		{
			myGameplay->endHazardChances = stoi((std::string)pNode->first_attribute()->value());
			myGameplay->endBonusChances = stoi((std::string)pNode->first_attribute()->next_attribute()->value());
		}
		else if ((std::string)pNode->name() == "LogRiver" || (std::string)pNode->name() == "TurtlesRiver")
		{
			if ((std::string)pNode->name() == "LogRiver")
			{
				rapidxml::xml_node<>* pNode2 = pNode->first_node();
				myGameplay->spawners.push_back(new LogSpawner(stof((std::string)pNode2->first_attribute()->next_attribute()->value()), stof((std::string)pNode2->first_attribute()->value()),
					stof((std::string)pNode->first_attribute()->next_attribute()->value()), stof((std::string)pNode->first_attribute()->value()), stof((std::string)pNode2->next_sibling()->value()),
					stof((std::string)pNode2->next_sibling()->next_sibling()->value()), 1.0f, spawnPosition));
				spawnPosition.y++;
			}
			else if ((std::string)pNode->name() == "TurtlesRiver")
			{
				rapidxml::xml_node<>* pNode2 = pNode->first_node();
				myGameplay->spawners.push_back(new TurtleSpawner(stof((std::string)pNode2->first_attribute()->next_attribute()->value()), stof((std::string)pNode2->first_attribute()->value()),
					stof((std::string)pNode->first_attribute()->next_attribute()->value()), stof((std::string)pNode->first_attribute()->value()), stof((std::string)pNode2->next_sibling()->value()), 1.0f, spawnPosition));
				spawnPosition.y++;

			}
			else if ((std::string)pNode->name() == "Road")
			{
				rapidxml::xml_node<>* pNode2 = pNode->first_node();
				myGameplay->spawners.push_back(new RoadSpawner(stoi((std::string)pNode->first_attribute()->value()),
					stof((std::string)pNode2->first_attribute()->next_attribute()->value()), stof((std::string)pNode2->first_attribute()->value()),
					stof((std::string)pNode2->next_sibling()->value()), spawnPosition));

				spawnPosition.y++;
			}

		}

	}
}
