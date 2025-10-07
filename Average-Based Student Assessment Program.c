#include <stdio.h>


// void loop 
void output(char name[4], float score, float average){
	if(score >= average) printf("%s lolos\n", name);
	else printf("%s tidak lolos\n", name);
}

int main(){
	
	//container of input 
	unsigned int i, n;
	float jo, li, bi, scr, tot, avg;
	
	// take user input 
	scanf("%d", &n);
	scanf("%f %f %f", &jo, &li, &bi);
	tot = jo+li+bi;
	
	// loop for process 
	for(i=0; i < n; i++){
		scanf("%f", &scr);
		tot += scr;
	}
	
	avg = tot/(n+3);
	
	output("Jojo", jo, avg);
	output("Lili", li, avg);
	output("Bibi", bi, avg);
	
	return 0;
}
