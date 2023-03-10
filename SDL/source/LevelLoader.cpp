  #include "LevelLoader.h"
#include "../dependencies/inc/XML/rapidxml.hpp"
#include "../dependencies/inc/XML/rapidxml_iterators.hpp"
#include "../dependencies/inc/XML/rapidxml_print.hpp"
#include "../dependencies/inc/XML/rapidxml_utils.hpp"
#include "Log.h"
#include "Turtle.h"
#include "RoadObject.h"


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

	myGameplay->maxTime = stof((std::string)pRoot->first_node()->value());
	//dynamic_cast<TimeBar*>(gamelay->gameUI.find("timeBar")->second)->SetMaxTime(stof((std::string)pRoot->first_node()->value()));
	pRoot = pRoot->first_node("Layout");

	myGameplay->endHazardChances = stof((std::string)pRoot->first_node()->first_attribute()->value());
	int spawnPosition = 0;

	std::vector<GameObject*>(linesObject);


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
					linesObject.push_back(new Log(stoi((std::string)pNode2->first_attribute()->next_attribute()->value()), stoi((std::string)pNode2->first_attribute()->value()),
						stoi((std::string)pNode->first_attribute()->next_attribute()->value()), stoi((std::string)pNode->first_attribute()->value()), stoi((std::string)pNode2->next_sibling()->value()),
						stoi((std::string)pNode2->next_sibling()->next_sibling()->value())));
					/*Spawner* spawn = new Spawner
					("log",
						stoi((std::string)pNode2->first_attribute()->next_attribute()->value()),
						stoi((std::string)pNode2->first_attribute()->value()),
						tile[(int)((rows * 14) + col)]->GetTransform().GetPosition().x,
						tile[(int)((rows * 14) + col)]->GetTransform().GetPosition().y,
						2 * (RM->gridX),
						0,
						stoi((std::string)pNode->first_attribute()->next_attribute()->value()),
						stoi((std::string)pNode->first_attribute()->value()),
						spawnPosition % 2,
						stoi((std::string)pNode2->next_sibling()->value()),
						stoi((std::string)pNode2->next_sibling()->next_sibling()->value())
						);

					gamelay->spawners.push_back(spawn);
					spawnPosition++;*/
				}
				else if (/*col == 0 && */(std::string)pNode->name() == "TurtlesRiver")
				{
					rapidxml::xml_node<>* pNode2 = pNode->first_node();
					linesObject.push_back(new Turtle(stoi((std::string)pNode2->first_attribute()->next_attribute()->value()), stoi((std::string)pNode2->first_attribute()->value()),
						stoi((std::string)pNode->first_attribute()->next_attribute()->value()), stoi((std::string)pNode->first_attribute()->value()), stoi((std::string)pNode2->next_sibling()->value())));

					/*Spawner* spawn = new Spawner
					("turtle",
						stoi((std::string)pNode2->first_attribute()->next_attribute()->value()),
						stoi((std::string)pNode2->first_attribute()->value()),
						tile[(int)((rows * 14) + col)]->GetTransform().GetPosition().x,
						tile[(int)((rows * 14) + col)]->GetTransform().GetPosition().y,
						2 * (RM->gridX),
						0,
						stoi((std::string)pNode->first_attribute()->next_attribute()->value()),
						stoi((std::string)pNode->first_attribute()->value()),
						spawnPosition % 2,
						stoi((std::string)pNode2->next_sibling()->value())
						);

					gamelay->spawners.push_back(spawn);
					spawnPosition++;*/
				}
			/*}*/
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
					linesObject.push_back(new RoadObject((std::string)pNode->first_attribute()->value(), 
						stoi((std::string)pNode2->first_attribute()->next_attribute()->value()),stoi((std::string)pNode2->first_attribute()->value()),
						stoi((std::string)pNode2->next_sibling()->value())));
					//Spawner* spawn = new Spawner
					//((std::string)pNode->first_attribute()->value(),
					//	stoi((std::string)pNode2->first_attribute()->next_attribute()->value()),
					//	stoi((std::string)pNode2->first_attribute()->value()),
					//	tile[(int)((rows * 14) + col)]->GetTransform().GetPosition().x,
					//	tile[(int)((rows * 14) + col)]->GetTransform().GetPosition().y,
					//	stoi((std::string)pNode2->next_sibling()->value()) * RM->gridX,
					//	0,
					//	spawnPosition % 2);

					//gamelay->spawners.push_back(spawn);
					//spawnPosition++;
				/*}*/
			/*}*/
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
