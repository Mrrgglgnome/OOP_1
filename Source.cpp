#include <stdio.h>
#include <locale.h>

class drob{
public:

	void Init(int ch, int zn){
		this->chisl = ch;
		this->znam = zn;
	}

	void Read(){
		printf("Введите числитель и знаменатель: ");
		scanf("%d %d", &this->chisl, &this->znam);
	}

	void Display(){
		printf("Числитель: %d, Знаменатель: %d\n", this->chisl, this->znam);
	}

	static drob Add(drob d1, drob d2){
		drob d;
		d.chisl = d1.chisl * d2.znam + d2.chisl * d1.znam;
		d.znam = d1.znam * d2.znam;
		return d;
	}

	float drob_ch(){
		float a;
		int b = this->chisl % this->znam;
		a = b / float(this->znam);
		return a;
	}

private:
	int chisl;
	int znam;
};

int main(){
	setlocale(LC_ALL, "rus");
	drob d1, d2, d3;
	d1.Read();
	d2.Read();
	d3 = drob::Add(d1, d2);
	d3.Display();
	printf("%f\n", d3.drob_ch());
	return 0;
}