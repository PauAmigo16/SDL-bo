  #include "LevelLoader.h"
#include "../dependencies/inc/XML/rapidxml.hpp"
#include "../dependencies/inc/XML/rapidxml_iterators.hpp"
#include "../dependencies/inc/XML/rapidxml_print.hpp"
#include "../dependencies/inc/XML/rapidxml_utils.hpp"
#include "LogSpawner.h"
#include "RoadSpawner.h"
#include "TurtleSpawner.h"


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

	//std::vector<GameObject*> tiles;
	rapidxml::xml_node<>* pRoot = doc.first_node();

	myGameplay->maxTime = stof((std::string)pRoot->first_node("MaxTime")->value());
	//dynamic_cast<TimeBar*>(gamelay->gameUI.find("timeBar")->second)->SetMaxTime(stof((std::string)pRoot->first_node()->value()));
	pRoot = pRoot->first_node("Layout");

	myGameplay->endHazardChances = stof((std::string)pRoot->first_node()->first_attribute()->value());
	Vector2 spawnPosition(0,2);


	/*Tile* tile[14 * 15];
	for (int i = 0; i < 14 * 15; i++)
	{
		tile[i] = new Tile;
	}
	float rows = 0;
	for (float col = 0; col < 14; col++)
	{

		tile[(int)((rows * 14) + col)]->SetTransform(col * RM->gridX, rows * RM->gridY, RM->gridX, RM->gridY, 0);
		tile[(int)((rows * 14) + col)]->IsLethal(false);
		tile[(int)((rows * 14) + col)]->SetImage({ 9 , 121, 24 , 16 });
		gamelay->tiles.push_back(tile[(int)((rows * 14) + col)]);
	}
	rows++;*/
		
	for (rapidxml::xml_node<>* pNode = pRoot->first_node(); pNode; pNode = pNode->next_sibling())
	{
		if ((std::string)pNode->name() == "EndZone")
		{
			/*for (float col = 0; col < 11; col++)
			{

				tile[(int)((rows * 14) + col)]->SetTransform(col * RM->windowWidht / 11, rows * RM->gridY, RM->windowWidht / 11, RM->gridY, 0);

				if ((int)col % 2 == 0)
				{
					tile[(int)((rows * 14) + col)]->IsLethal(true);
					tile[(int)((rows * 14) + col)]->SetImage({ 9 , 9, 24 , 16 });

				}
				else
				{
					tile[(int)((rows * 14) + col)]->IsLethal(false);
					tile[(int)((rows * 14) + col)]->SetImage({ 33 , 9, 24 , 16 });

					EndPosition* endPos = new EndPosition(tile[(int)((rows * 14) + col)]->GetTransform().GetPosition());

					gamelay->endPositions.push_back(endPos);
				}


				gamelay->tiles.push_back(tile[(int)((rows * 14) + col)]);
			}*/
		}
		else if ((std::string)pNode->name() == "LogRiver" || (std::string)pNode->name() == "TurtlesRiver")
		{
			/*for (float col = 0; col < 14; col++)
			{*/
			/*tile[(int)((rows * 14) + col)]->SetTransform(col * RM->gridX, rows * RM->gridY, RM->gridX, RM->gridY, 0);
			tile[(int)((rows * 14) + col)]->IsLethal(true);
			tile[(int)((rows * 14) + col)]->SetImage({ 9 , 25, 24 , 16 });
			gamelay->tiles.push_back(tile[(int)((rows * 14) + col)]);*/
			if (/*col == 0 && */(std::string)pNode->name() == "LogRiver")
			{
				rapidxml::xml_node<>* pNode2 = pNode->first_node();
				myGameplay->spawners.push_back(new LogSpawner(stof((std::string)pNode2->first_attribute()->next_attribute()->value()), stof((std::string)pNode2->first_attribute()->value()),
					stof((std::string)pNode->first_attribute()->next_attribute()->value()), stof((std::string)pNode->first_attribute()->value()), stof((std::string)pNode2->next_sibling()->value()),
					stof((std::string)pNode2->next_sibling()->next_sibling()->value()), 1.0f, spawnPosition));
				spawnPosition.y++;
			}
			else if (/*col == 0 && */(std::string)pNode->name() == "TurtlesRiver")
			{
				rapidxml::xml_node<>* pNode2 = pNode->first_node();
				myGameplay->spawners.push_back(new TurtleSpawner(stof((std::string)pNode2->first_attribute()->next_attribute()->value()), stof((std::string)pNode2->first_attribute()->value()),
					stof((std::string)pNode->first_attribute()->next_attribute()->value()), stof((std::string)pNode->first_attribute()->value()), stof((std::string)pNode2->next_sibling()->value()), 1.0f, spawnPosition));
				spawnPosition.y++;

			}
			else if ((std::string)pNode->name() == "SafeZone")
			{
				/*for (float col = 0; col < 14; col++)
				{

					tile[(int)((rows * 14) + col)]->SetTransform(col * RM->gridX, rows * RM->gridY, RM->gridX, RM->gridY, 0);
					tile[(int)((rows * 14) + col)]->IsLethal(false);
					tile[(int)((rows * 14) + col)]->SetImage({ 9 , 105, 24 , 16 });
					gamelay->tiles.push_back(tile[(int)((rows * 14) + col)]);
				}*/
			}
			else if ((std::string)pNode->name() == "Road")
			{
				/*for (float col = 0; col < 14; col++)
				{*/

				/*tile[(int)((rows * 14) + col)]->SetTransform(col * RM->gridX, rows * RM->gridY, RM->gridX, RM->gridY, 0);
				tile[(int)((rows * 14) + col)]->IsLethal(false);
				tile[(int)((rows * 14) + col)]->SetImage({ 9 , 121, 24 , 16 });
				gamelay->tiles.push_back(tile[(int)((rows * 14) + col)]);*/
				/*if (col == 0)
				{*/
				rapidxml::xml_node<>* pNode2 = pNode->first_node();
				myGameplay->spawners.push_back(new RoadSpawner(stoi((std::string)pNode->first_attribute()->value()),
					stof((std::string)pNode2->first_attribute()->next_attribute()->value()), stof((std::string)pNode2->first_attribute()->value()),
					stof((std::string)pNode2->next_sibling()->value()), spawnPosition));

				spawnPosition.y++;
			}
			/*rows++;*/
		}

		/*for (float col = 0; col < 14; col++)
		{

			tile[(int)((rows * 14) + col)]->SetTransform(col * RM->gridX, rows * RM->gridY, RM->gridX, RM->gridY, 0);
			tile[(int)((rows * 14) + col)]->IsLethal(false);
			tile[(int)((rows * 14) + col)]->SetImage({ 9 , 121, 24 , 16 });
			gamelay->tiles.push_back(tile[(int)((rows * 14) + col)]);
		}*/

	}
}
