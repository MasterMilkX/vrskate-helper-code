#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265

//Compile as: gcc circle_point.c -o circle_point -lm


void cartesianRot(float coords[2], float angle){
	float x = PI / 180;			//converts to radians

	float newCoords[2];
	newCoords[0] = (coords[0] * cos(x*angle)) - (coords[1] * sin(x*angle)); 
	newCoords[1] = (coords[1] * cos(x*angle)) + (coords[0] * sin(x*angle));

	coords[0] = newCoords[0];
	coords[1] = newCoords[1];
}


int main(){
	//setup the inputs
	float coords[2];
	int range[2];
	int iter;

	//get the inputs
	printf("Start coords (x,y): \n");
	scanf("%f %f", &coords[0], &coords[1]);
	printf("Range (min, max): \n");
	scanf("%d %d", &range[0], &range[1]);
	printf("Iterations #: \n");
	scanf("%d", &iter);


	//caculate stuffs
	int i;
	srand(time(0));
	for(i=0;i<iter;i++){
		int angle = (rand() % (21 - 16 + 1)) + 16;
		angle = angle * 10;
		angle = (rand() % 2 == 0 ? 1 : -1) * angle;
		cartesianRot(coords, angle);
		printf("%f %f @ %d\n", coords[0], coords[1], angle);
	}

}