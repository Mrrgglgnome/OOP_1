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
	printf("������� ��������� � �����������: ");
	scanf("%d %d", &d.chisl, &d.znam);
	return d;
}

void display(drob d){
	printf("���������: %d, �����������: %d\n", d.chisl, d.znam);
}

void add(){

}



int main(){
	setlocale(LC_ALL, "rus");
	struct drob d;
	d = read();
	display(d);
	return 0;
}