#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

class Persona{
public:
	void Init(string name, string arcana, int lvl, int str, int ma, int end, int ag, int lu){
		this->name = name;
		this->arcana = arcana;
		this->level = lvl;
		this->strength = str;
		this->magic = ma;
		this->endurance = end;
		this->agility = ag;
		this->luck = lu;
	}

	void Read(){
		cin >> this->name >> this->arcana >> this->level >> this->strength >> this->magic >> this->endurance >> this->agility >> this->luck;
	}

	void Display(){
		cout << "Persona's name: " << this->name << ", Persona's arcana: " << this->arcana << endl;
		cout << "Persona's stats:" << endl;
		cout << "Level: " << this->level << endl;
		cout << "Strength: " << this->strength << endl;
		cout << "Magic: " << this->magic << endl;
		cout << "Endurance: " << this->endurance << endl;
		cout << "Agility: " << this->agility << endl;
		cout << "Luck: " << this->luck << endl;
	}

	static Persona Add(Persona p1, Persona p2){
		Persona p;
		srand(time(0));
		int i = rand() % 2;
		p.name = p1.name.substr(0, p1.name.length() / 2) + p2.name.substr(p2.name.length() / 2, p2.name.length() - 1);
		if (i)
			p.arcana = p1.arcana;
		else
			p.arcana = p2.arcana;
		p.level = (p1.level + p2.level) / 2;
		p.strength = (p1.strength + p2.strength) / 2;
		p.magic = (p1.magic + p2.magic) / 2;
		p.endurance = (p1.endurance + p2.endurance) / 2;
		p.agility = (p1.agility + p2.agility) / 2;
		p.luck = (p1.luck + p2.luck) / 2;
		return p;
	}

	static void fight(Persona p1, Persona p2){
		srand(time(0));
		int f;
		int p1_luck = rand() % p1.luck, p2_luck = rand() % p2.luck;
		int p1_attack = p1.strength + p1.magic, p2_attack = p2.strength + p2.magic;
		for (int i = 0; i < p1.agility; i += 5)
			p1_attack *= p1_luck;
		for (int i = 0; i < p2.agility; i += 5)
			p2_attack *= p2_luck;
		int p1_damage = p1_attack / p2.endurance, p2_damage = p2_attack / p1.endurance;
		if (p1_damage > p2_damage)
			cout << "Winner: " << p1.name << endl;
		if (p2_damage > p1_damage)
			cout << "Winner: " << p2.name << endl;
		if (p2_damage == p1_damage)
			cout << "No winners" << endl;
	}

private:
	string name;
	string arcana;
	int level;
	int strength;
	int magic;
	int endurance;
	int agility;
	int luck;
};

int main(){
	Persona p1, p2, p3;
	p1.Read();
	p2.Read();
	p3 = Persona::Add(p1, p2);
	p3.Display();
	Persona::fight(p2, p3);
	return 0;
}