#include <stdio.h>

int convert(float a);

int main()
{
	printf("\t\t\t\t\t===================================\n");
	printf("\t\t\t\t\tWELCOME TO THE STUDY PLAN GENERATOR\n");
	printf("\t\t\t\t\t===================================\n\n");


	char module[20];
	int i,j;
	int recording[10];
	int time[10];
	int sub_total[50],pages[20],reading_min[20];
	int total= 0;
	float sleep,free;

	printf("how many modules do you want to add :");
	scanf("%d",&j); // j = 4

	for(i =0 ; i<j; i++) {
		printf("Enter a module name  :");
		scanf(" %20[^\n]", module);

		printf("Enter the number of lecture recording :");
		scanf("%d",&recording[i]);

		printf("Enter average length of a recording(in minutes): ");
		scanf("%d",&time[i]);

		printf("\n\n");
		printf("Enter the total numbers of pages of lecture notes :");
		scanf("%d", &pages[i]);

		printf("Enter how much time do you need(in minutes) to read 10 pages :");
		scanf("%d",&reading_min[i]);

		sub_total[i] = (recording[i] * time[i]) + (reading_min[i]*pages[i])/10;

		printf("\n\n\n");
		printf("Sub total hours =%d\n\n\n",sub_total[i]);

		total += sub_total[i]; //  total = total + sub_total;

	}
	printf("Total hours = %dhrs  %dmin\n\n",total/60,(total%60)); // 183 / 60 = 3 hrs 3 min

	printf("**************************************************************************************************************************************************\n\n");

	printf("Enter the number of sleeping hours approximatly perday(EX : hours.minuts = 5.30) :"); // 5.30 = 5 *60 + 0.30*100 = 330
	scanf("%f",&sleep);// hours

	int sleep_min = convert(sleep);// sleep(hours) - sleep (minutes) , sleep = 5.30;

	printf("Enter average free hours for a day(EX : hours.minuts = 5.30) :");
	scanf("%f",&free);

	int free_min = convert(free);

	float estimated_time_duration = total/free_min ;// 163min/ 30min = 5......

	if ( estimated_time_duration - (int)estimated_time_duration >0 ) {
		estimated_time_duration++;
		printf("Estimated time duration to complete your works : %d",(int)estimated_time_duration);
	} else {
		estimated_time_duration++;
		printf("Estimated time duration to complete your works : %d",(int)estimated_time_duration);
	}*/



	return 0;
}

int convert(float a)// float a = sleep = 5.30 ;
{

	return (int)a * 60 + ((a - (int)a)*100);// (int)a*60 + (a- (int)a)*100 = 5*60 + (5.30- 5)*100

}

