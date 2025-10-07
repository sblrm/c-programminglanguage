#include <stdio.h>
#include <string.h>
#include <math.h>

double power = 10000;
double cool = 1;
double cast = 60;
double aoe = 20;

void ap(double* power, double* cool, double* cast, double* aoe){
    *power += (*power * 0.2);
    *cool += (*cool * 0.3);
    *cast += (*cast * 0.15);
    *aoe += (*aoe * 0.05);
}

void cd(double* power, double* cool, double* cast, double* aoe){
    *power -= (*power * 0.3);
    *cool -= (*cool * 0.2);
    *cast += (*cast * 0.15);
    *aoe -= (*aoe * 0.5);
}

void ct(double* power, double* cool, double* cast, double* aoe){
    *power -= (*power * 0.5);
    *cool = *cool;
    *cast -= (*cast * 0.7);
    *aoe -= (*aoe * 0.9);
}

void ae(double* power, double* cool, double* cast, double* aoe){
    *power += (*power * 0.05);
    *cool += (*cool * 0.2);
    *cast += (*cast * 0.1);
    *aoe += (*aoe * 0.6);
}

void print_stat(){
    power = floor(power * 10) / 10;
    cool = floor(cool * 10) / 10;
    cast = floor(cast * 10) / 10;
    aoe = floor(aoe * 10) / 10;
    printf("Attack Power = %.1lf\n", power);
    printf("Cooldown = %.1lf Days\n", cool);
    printf("Cast Time = %.1lf seconds\n", cast);
    printf("AoE = %.1lf meters\n", aoe);
}

int main(){
    char up[100];
    scanf("%[^\n]", up); getchar();
    char* up2 = strtok(up, "-\n");
    while(up2 != NULL){
        if(strcmp("AP", up2) == 0){
            ap(&power, &cool, &cast, &aoe);
        }else if(strcmp("CD", up2) == 0){
            cd(&power, &cool, &cast, &aoe);
        }else if(strcmp("CT", up2) == 0){
            ct(&power, &cool, &cast, &aoe);
        }else if(strcmp("AE", up2) == 0){
            ae(&power, &cool, &cast, &aoe);
        }
        up2 = strtok(NULL, "-\n");
    }
    print_stat();
    return 0;
}