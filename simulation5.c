
/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
double magnitude(double x, double y, double z);
int orientation(double gx, double gy, double gz, int barf);
int close_to(double tolerance, double point, double value);
/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc simulation5.c -o simulation5
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -a -g -b | ./simulation5

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int triangle, circle, x_button, square;
    double ax, ay, az, gx, gy, gz;
	int barf=0;

    while (1)
    {
        scanf("%lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d",
              &ax, &ay, &az, &gx, &gy, &gz, &triangle, &circle, &x_button, &square);

		if (magnitude(ax, ay, az) <.2)
			barf = orientation(gx, gy, gz, barf);
		if(triangle ==1)
			break;
      
    }

    return 0;
}

double magnitude(double x, double y, double z)
{
   return sqrt( x*x + y*y+z*z);
}
int close_to(double tolerance, double point, double value){
if ((value >(point - tolerance) && (value < (point +tolerance))))
	return 1;
else 
	return 0;
}
int orientation(double gx, double gy, double gz, int barf){
	 
	 if(close_to(.25,1,gy)){
	 if (barf !=1){
		 printf("\nTOP\n");
	 barf = 1;}}
	 else if(close_to(.25,-1,gy)){
		 if(barf!=2){
		 printf("\nBOTTOM\n");
	 barf=2;}}
	 else if (close_to(.25, -1, gz)){
		 if(barf!=3){
		 printf("\nFRONT\n");
	 barf=3;}}
	 else if(close_to(.25,1,gz)){
		 if(barf!=4){
		 printf("\nBACK\n");
barf = 4;}}
	 else if(close_to(.25,1,gx)){
		 if (barf !=5){
		 printf("\nLEFT\n");
	 barf=5;}}
	 else if(close_to(.25,-1,gx)){
		 if(barf!=6){
		 printf("\nRIGHT\n");
	 barf  =6;}}
	 return barf;
}
		