#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265


void cartesianRot(float coords[2], float angle){
	float x = PI / 180;			//converts to radians

	float newCoords[2];
	newCoords[0] = (coords[0] * cos(x*angle)) - (coords[1] * sin(x*angle)); 
	newCoords[1] = (coords[1] * cos(x*angle)) + (coords[0] * sin(x*angle));

	coords[0] = newCoords[0];
	coords[1] = newCoords[1];
}

int main(){
	int i, lines;
	float x,y, angle;

	scanf("%d", &lines);
	float points[lines][2];
	float angles[lines];

	//import
	for(i=0;i<lines;i++){

		scanf("%f %f %f", &x, &y, &angle);
		points[i][0] = x;
		points[i][1] = y;
		angles[i] = angle;
	}

	//process
	for(i=0;i<lines;i++){
		x = points[i][0];
		y = points[i][1];
		angle = angles[i];


		printf("(%0.2f, %0.2f) rotated by %0.2f degrees\n", x, y, angle);
		float coords[2] = {x,y};
		cartesianRot(coords, angle);
		printf("(x', y') = (%0.2f, %0.2f)\n\n", coords[0], coords[1]);
	}

	return 0;
}

