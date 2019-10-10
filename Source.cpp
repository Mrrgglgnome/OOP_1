#include <stdio.h>
#include <locale.h>

typedef struct drob{
	int chisl;
	int znam;
};

drob init(int ch, int zn){
	drob d;
	d.chisl = ch;
	d.znam = zn;
	return d;
}

drob read(){
	drob d;
	printf("Введите числитель и знаменатель: ");
	scanf("%d %d", &d.chisl, &d.znam);
	return d;
}

void display(drob d){
	printf("Числитель: %d, Знаменатель: %d\n", d.chisl, d.znam);
}

drob add(drob a, drob b){
	drob  d;
	d.chisl = a.chisl * b.chisl;
	d.znam = a.znam * b.znam;
	return d;
}

float drob_ch(drob d){
	float a;
	int b = d.chisl % d.znam;
	a = b / float(d.znam);
	return a;
}

int main(){
	setlocale(LC_ALL, "rus");
	struct drob d1, d2, d3;
	d1 = read();
	d2 = read();
	d3 = add(d1, d2);
	display(d3);
	printf("%f\n", drob_ch(d3));
	return 0;
}