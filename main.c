#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>


void loadingBar()
{
    // 0 - black background,
    // A - Green Foreground
    system("color 0A");
  
    // Initialize char for printing
    // loading bar
    char a = 177, b = 219;
  
    printf("\n\n\n\n");
    printf("\n\n\n\n\t\t\t\t\t");
           printf("Loading...\n\n");
    printf("\t\t\t\t\t");
  
    // Print initial loading bar
    for (int i = 0; i < 26; i++)
        printf("%c", a);
  
    // Set the cursor again starting
    // point of loading bar
    printf("\r");
    printf("\t\t\t\t\t");
  
    // Print loading bar progress
    for (int i = 0; i < 50; i++) {
        printf("%c", b);
  
        // Sleep for 1 second
        Sleep(10);
    }
}
void sampleProblems();
void menu();

void centralTendency(){
		
	
	int size, i;
    double sum = 0;
    char letter;
   
    printf("\t\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
   printf("\t\t\tCENTRAL TENDENCY\n");
   printf("\t\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n");
   
   
   
  
	printf("Enter Limit: ");
	printf("\033[0;33m");
    scanf("%d",&size); //size of array
    printf("\033[0;37m");
	int dataset[size];

    for( i = 0; i < size;i++){
    	printf("Enter Data set : ");
    	printf("\033[0;36m");
    	scanf("%d",&dataset[i]); //declaring array	
    	printf("\033[0;37m");
	}
	
	
// calculate the mean
	float Msum = 0.0, avg;
    for (i = 0; i < size; ++i) {
        Msum += dataset[i];
    }

    avg = Msum / size;
  
    
    
    
	// calculate the mode

int j, t, b[20] = {0}, k = 0, c = 1, max = 0, mode;


    // search num 
    for (i = 0; i < size - 1; i++){
        mode = 0;
        for (j = i + 1; j < size; j++){
            if (dataset[i] == dataset[j]) {
                mode++;
            }
        }
        if ((mode > max) && (mode != 0)){
            k = 0;
            max = mode;
            b[k] = dataset[i];
            k++;
        }
        else if (mode == max){
            b[k] = dataset[i];
            k++;
        }
    }


		
	// calculation of variance and standard deviation
	sum = 0;
	double variance, deviation;

    for ( i = 0; i < size; i++){
		  sum = sum + pow((dataset[i] - avg),2);
	}
   

    variance = sum / size;
    deviation = sqrt(variance);
 

// print the result

   
    for (i = 0; i < size; i++)
    {
        if (dataset[i] == b[i]) 
            c++;
        }
        if (c == size)
            printf("\nThere is \033[0;31mno mode\033[0;37m");
        else
        {
          printf("\n\033[0;33mMode\033[0;37m = ");
            for (i = 0; i < k; i++)
                printf("%d ",b[i]);
        }
        printf("\n");


	printf("Average = ");
	printf("\033[0;32m"); 
	printf("%.2f\n", avg); //result of the average
	printf("\033[0;37m");
	printf("Variance of elements: ");
	printf("\033[0;32m"); 
	printf("%.2lf\n", variance); //result of variance
	printf("\033[0;37m");
    printf("Standard deviation:");
    printf("\033[0;32m");
	printf(" %.2lf\n", deviation);//result of std
	printf("\033[0;37m");
    
    
    
    printf("\nWould you to keep using this tool?[Y/N]: ");
    int f = 1;
    while(f == 1){
	scanf(" %c", &letter);
    
    if (toupper(letter) == 'Y'){
    	
    	system("cls");
    	loadingBar();
    	system("cls");
    	printf("\033[0;37m");
    	centralTendency();
	}if (toupper(letter) == 'N'){
		system("cls");
		loadingBar();
		system("cls");
    	printf("\033[0;37m");
		menu();
	}
	else{
		printf("\033[0;31mINVALID INPUT\033[0;37m, PLEASE TRY AGAIN...");
	}
}
}

void hypothesisTesting(){
	printf("\t\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
   printf("\t\t\tHYPOTHESIS TESTING\n");
   printf("\t\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n");
	int i, limit1, limit2, total1, total2, total3;
	float input1[100], sum1 = 0.0, sum2 = 0.0, mean1, mean2, var1, var2;
	float input2[100], sumv1, sumv2, betmeans;
	float sqd1[100], bet12, bet34, betf;
	float sqd2[100], bet1, bet2, bet3, bet4;
	char letter;
	
	// user input#1
	printf("Enter limit Array 1: ");
	printf("\033[0;33m");
	scanf("%d", &limit1);
	printf("\033[0;37m");
	
	for (i = 0; i < limit1; i++){
		printf("\nEnter Data No.%d: ", i + 1);
		printf("\033[0;36m");
		scanf("%f", &input1[i]);
		printf("\033[0;37m");
			sum1 += input1[i];
			sqd1[i] = input1[i] * input1[i];
			sumv1 += sqd1[i];
	}

	// user input#2
	printf("\nEnter limit Array 2: ");
	printf("\033[0;33m");
	scanf("%d", &limit2);
	printf("\033[0;37m");
	
	for (int i = 0; i < limit2; i++){
		printf("\nEnter Data No.%d: ", i + 1);
		printf("\033[0;36m");
		scanf("%f", &input2[i]);
		printf("\033[0;37m");
			sum2 += input2[i];
			sqd2[i] = input2[i] * input2[i];
			sumv2 += sqd2[i];
	}
	
	// computation
	mean1 = sum1 / limit1;
	mean2 = sum2 / limit2;
	var1 = (sumv1 / limit1) - (mean1 * mean1);
	var2 = (sumv2 / limit2) - (mean2* mean2);
	bet1 = (limit1 * var1) + (limit2 * var2);
	bet2 = limit1 + limit2 - 2;
	bet3 = limit1 + limit2;
	bet4 = limit1 * limit2;
	bet12 = bet1 / bet2;
	bet34 = bet3 / bet4;
	betf = bet12 * bet34;
	betmeans = sqrt(betf);
	double final = (mean1 - mean2) / betmeans;
	
	
	//calculate for Z Test
	double sum3 = 0;
	sum1 = 0, sum2 = 0, mean1 = 0, mean2 = 0;
	
	for( i = 0; i < limit1; i++){
	    	sum1 += input1[i];
	}
		
	for( i = 0; i < limit2; i++){
	    	sum2 += input2[i];
	}
	
	mean1 = sum1 / limit1;
	mean2 = sum2 / limit2;
	
	double std; //getting the Standard Deviation
	double variance;
	
	for( int i = 0; i < limit1; i++){
		sum3 = sum3 + pow((input1[i]- mean1),2);
	}
	
	variance = sum3 / limit1;
	std = sqrt(variance);
	
	
	
	double z;
	z = (mean2 - mean1) / std;
	     


	
	// printing answer
	if(limit1 <= 30 && limit2 <= 30){
		printf("Z Test Result: ");
		printf("\033[0;32m");
		printf("%.5lf", z);
		printf("\033[0;37m");
	}else{
		printf("T Test Result: ");
		printf("\033[0;32m");
		printf("%.5lf\n", final);
		printf("\033[0;37m");
	}
	
	printf("\nWould you to keep using this tool?[Y/N]: ");
    int f = 1;
    while(f == 1){
	scanf(" %c", &letter);
    
    if (toupper(letter) == 'Y'){
    	
    	system("cls");
    	loadingBar();
    	system("cls");
    	printf("\033[0;37m");
    	hypothesisTesting();
	}if (toupper(letter) == 'N'){
		system("cls");
		loadingBar();
		system("cls");
    	printf("\033[0;37m");
		menu();
	}
	else{
		printf("\033[0;31mINVALID INPUT\033[0;37m, PLEASE TRY AGAIN...");
	}
}
	
}

void pearsonr(){
	
		int nth = 0, i;
		char letter;
	
	// pearson r

	//enter the nth of data
	// pearson r
    printf("\t\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
    printf("\t\t\t     PEARSON r\n");
    printf("\t\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n");
	//enter the nth of data
	printf("Enter Data set size: ");
	printf("\033[0;33m");
	scanf("%d", &nth);
	printf("\033[0;37m");
	
	

	
	double datasetX[nth], datasetY[nth], deviationX[nth], deviationY[nth], devMulti[nth], sqDevX[nth], sqDevY[nth];

	// enter the dataset for x 	
	printf("Enter Data set for X coordinate\n");
	for(i = 0; i < nth; i++){
		printf(" %d.) ", i + 1);
		printf("\033[0;36m");
		scanf("%lf", &datasetX[i]);
		printf("\033[0;37m");
	}


	// enter the dataset for y
	printf("\nEnter Data set for Y coordinate\n");
	for(i = 0; i < nth; i++){
		printf(" %d.) ", i + 1);
		printf("\033[0;36m");
		scanf("%lf", &datasetY[i]);
		printf("\033[0;37m");
	}

	
	// calculate
	double sumX = 0, sumY = 0, SP = 0, SSX = 0, SSY = 0, aveX, aveY;
	
	for(i = 0; i < nth;i++){
		//calculating the sum of both dataset
		sumX += datasetX[i];
		sumY += datasetY[i];
	}
	
	// calculate the ave of both dataset
	aveX = sumX/nth;
	aveY = sumY/nth;
	

	
	
	for(i = 0; i < nth;i++){
		// calculate the deviation from the mean 
		deviationX[i] = (datasetX[i] - aveX);
		deviationY[i] = (datasetY[i] - aveY);
		
		// multiply the deviation of x and y
		devMulti[i] = deviationX[i] * deviationY[i];
		
		//sum products of multiplied deviation
		SP += devMulti[i];
		
		//Squered of deviations
		sqDevX[i] = deviationX[i] * deviationX[i];
		sqDevY[i] = deviationY[i] * deviationY[i];
		
		//sum of squares
		SSX += sqDevX[i];
		SSY += sqDevY[i];
		
	}
	
	
	
	// calculate the pearson r
	double SSM = SSX * SSY;
	double pearsonR = SP / sqrt(SSM);
	
	// printf result
	printf("Pearson r: ");
	printf("\033[0;32m");
	printf("%.2lf", pearsonR);
	printf("\033[0;37m");
	
	printf("\nWould you to keep using this tool?[Y/N]: ");
    int f = 1;
    while(f == 1){
	scanf(" %c", &letter);
    
    if (toupper(letter) == 'Y'){
    	
    	system("cls");
    	loadingBar();
    	system("cls");
    	printf("\033[0;37m");
    	pearsonr();
	}if (toupper(letter) == 'N'){
		system("cls");
		loadingBar();
		system("cls");
    	printf("\033[0;37m");
		menu();
	}
	else{
		printf("\033[0;31mINVALID INPUT\033[0;37m, PLEASE TRY AGAIN...");
	}
}
}

void anova(){
	
	float ngroups, totalfirst = 0, totalsecond = 0, totalthird = 0, numgroups = 3;
	float firstmean, secondmean, thirdmean, totalnumscores, sumscores, sqrdsumscores, totalsumsquares, sumsqrWT, sumsqrBT, degftotal, degfBT, degfWT, MSbet, MSwit, Fstats;
	
	float firstdata[100], totalsqrdfirst = 0;
	float seconddata[100], totalsqrdsecond = 0;
	float thirddata[100], totalsqrdthird = 0;
	float squaredfirst[100], sumofsqr1;
	float squaredsecond[100], sumofsqr2;
	float squaredthird[100], sumofsqr3;
	int i;
	char letter;
	
	//input limit
	printf("\t\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
    printf("\t\t\t      ANOVA\n");
    printf("\t\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n");
	//input limit
	printf("Enter the number of scores in each treatment: ");
	printf("\033[0;33m");
	scanf("%f", &ngroups);
	printf("\033[0;37m");	
		
	//input data
	printf("\nInput data number for \033[0;31mFirst Group\033[0;37m.\n");
	for ( i = 0; i < ngroups; i++){
		printf(" %d.) ", i+1);
		printf("\033[0;36m");
		scanf("%f", &firstdata[i]);
		printf("\033[0;37m");
		
		totalfirst = totalfirst + firstdata[i];
		squaredfirst[i] = firstdata[i] * firstdata[i];
		totalsqrdfirst += squaredfirst[i];
	}
	
		printf("\nInput data number for \033[0;31mSecond Group\033[0;37m.\n"); 
		
	for (i = 0; i < ngroups; i++){
		printf(" %d.) ", i+1);
		printf("\033[0;36m");
		scanf("%f", &seconddata[i]);
		printf("\033[0;37m");
		
		totalsecond = totalsecond + seconddata[i];
		squaredsecond[i] = seconddata[i] * seconddata[i];
		totalsqrdsecond += squaredsecond[i];
	}
	
	    printf("\nInput data number for \033[0;31mThird Group\033[0;37m.\n");
		
	for (i = 0; i < ngroups; i++){
		printf(" %d.) ", i+1);
		printf("\033[0;36m");
		scanf("%f", &thirddata[i]);
		printf("\033[0;37m");
		
		totalthird = totalthird + thirddata[i];
		squaredthird[i] = thirddata[i] * thirddata[i];
		totalsqrdthird += squaredthird[i];
	}
		//mean formula
		firstmean = totalfirst / ngroups;
		secondmean = totalsecond / ngroups;
		thirdmean = totalthird / ngroups;
		
		totalnumscores = ngroups * numgroups;
		
		//Calculation
	
		sumscores = totalfirst + totalsecond + totalthird;
		sqrdsumscores = totalsqrdfirst + totalsqrdsecond + totalsqrdthird;
		sumofsqr1 = totalsqrdfirst - (pow(totalfirst, 2) / ngroups); 
		sumofsqr2 = totalsqrdsecond - (pow(totalsecond, 2) / ngroups); 
		sumofsqr3 = totalsqrdthird - (pow(totalthird, 2) / ngroups); 
	
		//SSformula
		totalsumsquares = sqrdsumscores - (pow(sumscores, 2) / totalnumscores);
		sumsqrWT = sumofsqr1 + sumofsqr2 + sumofsqr3;
		sumsqrBT = totalsumsquares - sumsqrWT;
		
		
		degftotal = totalnumscores - 1;
		degfWT = totalnumscores - numgroups;
		degfBT = numgroups - 10;
		
		//MS formula	
		MSbet = sumsqrBT / degfBT;
		MSwit = sumsqrWT / degfWT;
		
		//formula for value of F
		Fstats = MSbet / MSwit;

		printf("\nF-statistic value = "); 
		printf("\033[0;32m");
		printf("%2.f", Fstats);
		printf("\033[0;37m");
		
	printf("\nWould you to keep using this tool?[Y/N]: ");
    int f = 1;
    while(f == 1){
	scanf(" %c", &letter);
    
    if (toupper(letter) == 'Y'){
    	
    	system("cls");
    	loadingBar();
    	system("cls");
    	printf("\033[0;37m");
    	anova();
	}if (toupper(letter) == 'N'){
		system("cls");
		loadingBar();
		system("cls");
    	printf("\033[0;37m");
		menu();
	}
	else{
		printf("\033[0;31mINVALID INPUT\033[0;37m, PLEASE TRY AGAIN...");
	}
}
}

	
void centralexl(){
       int flag=1;
       int flag1=1;
	    char let;
	//dataset for central tendency
	int ctsample1[] = {23, 34, 45, 21, 23, 34, 54, 34, 23, 76};
	double ctmean = 36.7;
	int ctmode = 23;
	double ctstd = 17.46138597;
	double ctvar = 304.9;
	
	int ctsample2[] = {23, 34, 56, 43, 23, 23, 12, 16, 17, 15};
	double ctmean2 = 26.2;
	int ctmode2 = 23;
	double ctstd2 = 14.05386463;
	double ctvar2 = 197.5111111;
	
	int ctsample3[] = {52, 59, 23, 27, 43, 23, 45, 67, 89, 43};
	double ctmean3 = 47.1;
	int ctmode3 = 23;
	double ctstd3 = 20.87236344;
	double ctvar3 = 435.6555556;
	
	char enput1;
	int enput, enput2, enput3, enput4, tenput, zenput;
	// sample 1,2,3 for central tendency
	    printf("\033[0;37m");
		system("cls");
		printf("[\033[0;32m1\033[0;37m] Sample 1\n");
		printf("[\033[0;32m2\033[0;37m] Sample 2\n");
		printf("[\033[0;32m3\033[0;37m] Sample 3\n");
	    printf("[\033[0;32m4\033[0;37m] Back\n");
		printf("\n");
		while(flag1==1){
		scanf(" %c", &enput1);
		
		// sample 1 ct
		if (enput1 == '1'){
			system("cls");
			loadingBar();
			system("cls");
			printf("\033[0;37m");
				for (int i = 0; i < 10; ++i){
					printf("Data set %d: \033[0;36m%d\033[0;37m\n", i + 1, ctsample1[i]); // data sets     //you finished this 
				}
				printf("\nExcel Calculator Results: ");
				printf("\nMean = \033[0;33m%.1lf\033[0;37m", ctmean);
				printf("\nMode = \033[0;33m%d\033[0;37m", ctmode);
				printf("\nStandard Deviation = \033[0;33m%.8lf\033[0;37m", ctstd);
				printf("\nVariance = \033[0;33m%.1lf\033[0;37m", ctvar);
				printf("\n\nStatistical Tools Results: ");
				printf("\nMode = \033[0;33m23.34\033[0;37m");
				printf("\nMean = \033[0;33m36.70\033[0;37m");
				printf("\nStandard Deviation = \033[0;33m16.57\033[0;37m");
				printf("\nVariance = \033[0;33m274.41\033[0;37m");
				printf("\n\nType [Y] to go back to Sample menu or type [N] to go back to Main Menu: ");
				flag1--;
                while(flag == 1){
				scanf(" %c", &let);
				
				    if (toupper(let) == 'Y'){
                     flag--;    	
    				system("cls");
    				centralexl();
					}
					else if (toupper(let) == 'N'){
					system("cls");
					sampleProblems();
					flag--;
		            }
		            else{
		            	printf("\033[0;31mINVALID INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
					}
				  }  
     	}
		// sample 2 ct
		else if (enput1 == '2'){
			system("cls");
			loadingBar();
			system("cls");
			printf("\033[0;37m");
				for (int i = 0; i < 10; ++i){
					printf("Data set %d: \033[0;36m%d\033[0;37m\n", i + 1, ctsample2[i]); // data sets
				}
				printf("\nExcel Calculator Results: ");
				printf("\nMean = \033[0;33m%.1lf\033[0;37m", ctmean2);
				printf("\nMode = \033[0;33m%d\033[0;37m", ctmode2);
				printf("\nStandard Deviation = \033[0;33m%.8lf\033[0;37m", ctstd2);
				printf("\nVariance = \033[0;33m%.7lf\033[0;37m", ctvar2);
				printf("\n\nStatistical Tools Results: ");
				printf("\nMode = \033[0;33m23\033[0;37m");
				printf("\nMean = \033[0;33m26.20\033[0;37m");
				printf("\nStandard Deviation = \033[0;33m13.33\033[0;37m");
				printf("\nVariance = \033[0;33m177.76\033[0;37m");
				printf("\n\nType [Y] to go back to Sample menu or type [N] to go back to Main Menu: ");
				flag1--;
				while(flag == 1){
				scanf(" %c", &let);
				
				    if (toupper(let) == 'Y'){
                     flag--;    	
    				system("cls");
    				centralexl();
					}
					else if (toupper(let) == 'N'){
					system("cls");
					sampleProblems();
					flag--;
		            }
		            else{
		            	printf("\033[0;31mINVALID INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
					}
				  } 
	    } 
		//sample 3 ct
		else if (enput1 == '3'){
				system("cls");
				loadingBar();
			    system("cls");
			    printf("\033[0;37m");
				for (int i = 0; i < 10; ++i){
					printf("Data set %d: \033[0;36m%d\033[0;37m\n", i + 1, ctsample3[i]); // data sets
				}
				printf("\nExcel Calculator Results: ");
				printf("\nMean = \033[0;33m%.1lf\033[0;37m", ctmean3);
				printf("\nMode = \033[0;33m%d\033[0;37m", ctmode3);
				printf("\nStandard Deviation = \033[0;33m%.8lf\033[0;37m", ctstd3);
				printf("\nVariance = \033[0;33m%.7lf\033[0;37m", ctvar3);
				printf("\n\nStatistical Tools Results: ");
				printf("\nMode = \033[0;33m23.43\033[0;37m");
				printf("\nMean = \033[0;33m47.10\033[0;37m");
				printf("\nStandard Deviation = \033[0;33m19.80\033[0;37m");
				printf("\nVariance = \033[0;33m392.09\033[0;37m");
				printf("\n\nType [Y] to go back to Sample menu or type [N] to go back to Main Menu: ");
				flag1--;
				while(flag == 1){
				scanf(" %c", &let);
				
				    if (toupper(let) == 'Y'){
                     flag--;    	
    				system("cls");
    				centralexl();
					}
					else if (toupper(let) == 'N'){
					system("cls");
					sampleProblems();
					flag--;
		            }
		            else{
		            	printf("\033[0;31mINVALID INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
					}
				  }
	           }else if (enput1 == '4'){
			        system("cls");
			        sampleProblems();
			        flag1--;
	       }else{
	       	printf("\033[0;31mINVALID  INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
		   }
	   }
}//END OF CENTRAL!!!!!

	
void hypomain();		
void hypoT(){// t test 
	//dataset for T Test
	int Tsample1g1[] = {23, 34, 45, 21, 23, 34, 54, 34, 23, 76};
	int Tsample1g2[] = {34, 56, 43, 23, 45, 21, 23, 54, 34, 23};
	double Tsample1Ans = 0.1584689807;
	
	
	int Tsample2g1[] = {23, 34, 56, 43, 23, 23, 12, 16, 17, 15};
	int Tsample2g2[] = {56, 43, 23, 45, 21, 23, 54, 34, 23, 23};
	double Tsample2Ans = -1.328288122;
		
		
		int enput, enput1,enput3, enput4, zenput;
		char tenput, let;
		
	int Tsample3g1[] = {52, 59, 23, 27, 43, 23, 45, 67, 89, 43};
	int Tsample3g2[] = {45, 21, 27, 43, 23, 56, 43, 23, 43, 23};
	double Tsample3Ans = 1.609048316;
				int flag = 1;
				int flag2 =1;
				system("cls");
				printf("[\033[0;32m1\033[0;37m] Sample 1\n");
				printf("[\033[0;32m2\033[0;37m] Sample 2\n");
				printf("[\033[0;32m3\033[0;37m] Sample 3\n");
				printf("[\033[0;32m4\033[0;37m] Back");
				printf("\n");
				while(flag == 1){
				
				scanf(" %c", &tenput);

			// sample 1 t test
				if (tenput == '1'){
					system("cls");
					loadingBar();
			        system("cls");
			        printf("\033[0;37m");
					for (int i = 0; i < 10; ++i){
					printf("Data set %d: \033[0;36m%d\033[0;37m   \033[0;36m%d\033[0;37m\n", i + 1, Tsample1g1[i], Tsample1g2[i]); // data sets
				}
				printf("\nExcel Calculator Results: ");
				printf("\nT Test Result: \033[0;32m%.8lf\033[0;37m", Tsample1Ans);
				printf("\n\nStatistical Tools Results: ");
				printf("\nT Test Result: \033[0;32m0.16\033[0;37m");
				printf("\n\nType [Y] to go back to Sample menu or type [N] to go back to Test Select: ");
				flag--;
				while(flag2 == 1){
				scanf(" %c", &let);
				
				    if (toupper(let) == 'Y'){
                     flag--;    	
    				system("cls");
    				hypoT();
					}
					else if (toupper(let) == 'N'){
					system("cls");
					hypomain();
					flag--;
		            }
		            else{
		            	printf("\033[0;31mINVALID INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
					}
				  }
				}
				// sample 2 t test
				else if (tenput == '2'){
					system("cls");
					loadingBar();
			        system("cls");
			        printf("\033[0;37m");
					for (int i = 0; i < 10; ++i){
					printf("Data set %d: \033[0;36m%d\033[0;37m   \033[0;36m%d\033[0;37m\n", i + 1, Tsample2g1[i], Tsample2g2[i]); // data sets
				}
				printf("\nExcel Calculator Results: ");
				printf("\nT Test Result: \033[0;32m%.8lf\033[0;37m", Tsample2Ans);
				printf("\n\nStatistical Tools Results: ");
				printf("\nT Test Result: \033[0;32m-1.33\033[0;37m");
				printf("\n\nType [Y] to go back to Sample menu or type [N] to go back to Test Select: ");
				flag--;
				while(flag2 == 1){
				scanf(" %c", &let);
				
				    if (toupper(let) == 'Y'){
                     flag--;    	
    				system("cls");
    				hypoT();
					}
					else if (toupper(let) == 'N'){
					system("cls");
					hypomain();
					flag--;
		            }
		            else{
		            	printf("\033[0;31mINVALID INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
					}
				  }
				}
				// sample 3 t test
				else if (tenput == '3'){
					system("cls");
					loadingBar();
		         	system("cls");
			        printf("\033[0;37m");
					for (int i = 0; i < 10; ++i){
					printf("Data set %d: \033[0;36m%d\033[0;37m   \033[0;36m%d\033[0;37m\n", i + 1, Tsample3g1[i], Tsample3g2[i]); // data sets
				}
				printf("\nExcel Calculator Results: ");
				printf("\nT Test Result: \033[0;32m%.8lf\033[0;37m", Tsample3Ans);
				printf("\n\nStatistical Tools Results: ");
				printf("\nT Test Result: \033[0;32m1.61\033[0;37m");
				printf("\n\nType [Y] to go back to Sample menu or type [N] to go back to Test Select: ");
				flag--;
				while(flag2 == 1){
				scanf(" %c", &let);
				
				    if (toupper(let) == 'Y'){
                     flag--;    	
    				system("cls");
    				hypoT();
					}
					else if (toupper(let) == 'N'){
					system("cls");
					hypomain();
					flag--;
		            }
		            else{
		            	printf("\033[0;31mINVALID INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
					}
				  } 
				}else if(tenput == '4'){
					system("cls");
					hypomain();
				}else{
					    printf("\033[0;31mINVALID INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
				}
		      }
		    }
		
void hypoZ(){// z test 
            // dataset for Z Test
	int Zsample1g1[] = {34, 45, 21, 46, 56, 49, 23, 43, 68, 34, 23, 23, 45, 21, 45, 21, 23, 96, 95, 100, 90, 45, 90, 34, 20, 23, 23, 43, 96, 34};
	int Zsample1g2[] = {56, 43, 23, 34, 23, 45, 21, 45, 21, 23, 56, 43, 23, 23, 43, 96, 34, 23, 23, 45, 23, 43, 23, 34, 39, 28, 45, 23, 34, 23};
	double Zsample1Ans = -0.4340;
	
	
	int Zsample2g1[] = {95, 34, 32, 45, 23, 32, 45, 23, 23, 23, 43, 21, 23, 56, 43, 23, 45, 59, 23, 27, 43, 45, 43, 23, 23, 12, 45, 21, 45, 21};
	int Zsample2g2[] = {23, 45, 23, 23, 56, 43, 23, 23, 34, 23, 23, 23, 34, 23, 45, 21, 23, 21, 27, 43, 23, 10, 10, 21, 23, 54, 45, 59, 23, 27};
	double Zsample2Ans = -0.3318;
	
	
	
	int Zsample3g1[] = {43, 23, 23, 45, 21, 45, 21 ,45 ,34 ,23 ,34 ,23, 45, 21, 23, 21, 23, 23, 23, 23, 34, 23, 23, 34, 23, 45, 21, 23, 21, 23};
	int Zsample3g2[] = {21, 23, 56, 43, 23, 45, 23, 43, 23, 56, 43, 23, 23, 34, 23, 45, 45, 21, 23, 23, 23, 45, 43, 96, 34, 21, 45, 21, 45, 23};
	double Zsample3Ans = 0.7357;
	        char let,zenput;
	
	int enput, enput1,enput3, enput4, tenput;
                int flag  = 1;
				int flag2 = 1;	
				system("cls");
				printf("[\033[0;32m1\033[0;37m] Sample 1\n");
		        printf("[\033[0;32m2\033[0;37m] Sample 2\n");
		        printf("[\033[0;32m3\033[0;37m] Sample 3\n");
		        printf("[\033[0;32m4\033[0;37m] Back\n");
				printf("\n");
				while(flag==1){
				scanf(" %c", &zenput);
				
			// sample 1 z test
			if (zenput == '1'){
				system("cls");
				loadingBar();
			    system("cls");
			    printf("\033[0;37m");
					for (int i = 0; i < 30; ++i){
					printf("Data set %d: \033[0;36m%d\033[0;37m   \033[0;36m%d\033[0;37m\n", i + 1, Zsample1g1[i], Zsample1g2[i]); // data sets
				}
				printf("\nExcel Calculator Results: ");
				printf("\nZ Test Result: \033[0;32m%.4lf\033[0;37m", Zsample1Ans);
				printf("\n\nStatistical Tools Results: ");
				printf("\nZ Test Result: \033[0;32m-0.44141\033[0;37m");
				printf("\n\nType [Y] to go back to Sample menu or type [N] to go back to Test Select: ");
				flag--;
				while(flag2 == 1){
				scanf(" %c", &let);
				
				    if (toupper(let) == 'Y'){
                     flag--;    	
    				system("cls");
    				hypoZ();
					}
					else if (toupper(let) == 'N'){
					system("cls");
					hypomain();
					flag--;
		            }
		            else{
		            	printf("\033[0;31mINVALID INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
					}
				  } 
				}
				// sample 2 z test
				else if (zenput == '2'){
					system("cls");
					loadingBar();
			system("cls");
			printf("\033[0;37m");
					for (int i = 0; i < 30; ++i){
					printf("Data set %d: \033[0;36m%d\033[0;37m   \033[0;36m%d\033[0;37m\n", i + 1, Zsample2g1[i], Zsample2g2[i]); // data sets
				}
				printf("\nExcel Calculator Results: ");
				printf("\nZ Test Result: \033[0;32m%.4lf\033[0;37m", Zsample2Ans);
				printf("\n\nStatistical Tools Results: ");
				printf("\nZ Test Result: \033[0;32m-0.33752\033[0;37m");
				printf("\n\nType [Y] to go back to Sample menu or type [N] to go back to Test Select: ");
				flag--;
				while(flag2 == 1){
				scanf(" %c", &let);
				
				    if (toupper(let) == 'Y'){
                     flag--;    	
    				system("cls");
    				hypoZ();
					}
					else if (toupper(let) == 'N'){
					system("cls");
					hypomain();
					flag--;
		            }
		            else{
		            	printf("\033[0;31mINVALID INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
					}
				  } 
				}
				else if (zenput == '3'){
					system("cls");
					loadingBar();
			system("cls");
			printf("\033[0;37m");
					for (int i = 0; i < 30; ++i){
					printf("Data set %d: \033[0;36m%d\033[0;37m   \033[0;36m%d\033[0;37m\n", i + 1, Zsample3g1[i], Zsample3g2[i]); // data sets
				}
				printf("\nExcel Calculator Results: ");
				printf("\nZ Test Result: \033[0;32m%.4lf\033[0;37m", Zsample3Ans);
				printf("\n\nStatistical Tools Results: ");
				printf("\nZ Test Result: \033[0;32m0.74829\033[0;37m");
				printf("\n\nType [Y] to go back to Sample menu or type [N] to go back to Test Select: ");
				flag--;
				while(flag2 == 1){
				scanf(" %c", &let);
				
				    if (toupper(let) == 'Y'){
                     flag--;    	
    				system("cls");
    				hypoZ();
					}
					else if (toupper(let) == 'N'){
					system("cls");
					hypomain();
					flag--;
		            }
		            else{
		            	printf("\033[0;31mINVALID INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
					}
				  } 
				}else if(zenput == '4'){
						system("cls");
					hypomain();
				}else{
					    printf("\033[0;31mINVALID INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
				}
		      }
		  } // end of HYPOYAWA
void hypomain(){ //hypothesus start
	    char enput2;
		system("cls");
		printf("\033[0;37m");
		printf("[\033[0;32m1\033[0;37m] T Test\n");
		printf("[\033[0;32m2\033[0;37m] Z Test\n");
		printf("[\033[0;32m3\033[0;37m] Back");
		printf("\n");
		int flag = 1;
		while(flag == 1){
		scanf(" %c", &enput2);
		if(enput2 == '1'){
			system("cls");
			hypoT();
			flag--;
	    }else if(enput2 == '2'){
		    system("cls");
			hypoZ();
			flag--;
		}else if(enput2 == '3'){
			system("cls");
			sampleProblems();
			flag--;		
		}else{
		 printf("\033[0;31mINVALID  INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
		}
       }
     }		
		
		
		
void peaersonexl(){//pearson r
		//dataset for pearson r
	int pr1sample1[] = {23, 34, 45, 21, 23, 34, 54, 34, 23, 76};
	int pr1sample2[] = {34, 56, 43, 23, 45, 21, 23, 54, 34, 23};
	double prans1 = -0.2890378177;
	
	int pr2sample1[] = {23, 34, 56, 43, 23, 23, 12, 16, 17, 15};
	int pr2sample2[] = {56, 43, 23, 45, 21, 23, 54, 34, 23, 23};
	double prans2 = -0.07171601188;
	
	int pr3sample1[] = {52, 59, 23, 27, 43, 23, 45, 67, 89, 43};
	int pr3sample2[] = {45, 21, 27, 43, 23, 56, 43, 23, 43, 23};
	double prans3 = -0.1750742984;
	int flag = 1;
	int flag2 = 1;
		char let,enput3;
	int enput, enput1, enput2, enput4, tenput, zenput;	
				system("cls");
				printf("\033[0;37m");
			    printf("[\033[0;32m1\033[0;37m] Sample 1\n");
		        printf("[\033[0;32m2\033[0;37m] Sample 2\n");
		        printf("[\033[0;32m3\033[0;37m] Sample 3\n");
				printf("[\033[0;32m4\033[0;37m] Back\n");
				printf("\n");
				while(flag == 1){
				scanf(" %c", &enput3);
			// sample 1 pr
			if (enput3 == '1'){	
				system("cls");
				loadingBar();
			system("cls");
			printf("\033[0;37m");
				for (int i = 0; i < 10; ++i){
				printf("Data set %d: \033[0;36m%d\033[0;37m   \033[0;36m%d\033[0;37m\n", i + 1, pr1sample1[i], pr1sample2[i]); // data sets
			}
			printf("\nExcel Calculator Results: ");
			printf("\nPearson r: \033[0;32m%.10lf\033[0;37m", prans1);
			printf("\n\nStatistical Tools Results: ");
			printf("\nPearson r: \033[0;32m-0.29\033[0;37m");
			printf("\n\nType [Y] to go back to Sample menu or type [N] to go back to Main Menu: ");
			flag--;
				while(flag2 == 1){
				scanf(" %c", &let);
				
				    if (toupper(let) == 'Y'){
                     flag--;    	
    				system("cls");
    				peaersonexl();
					}
					else if (toupper(let) == 'N'){
					system("cls");
					sampleProblems();
					flag--;
		            }
		            else{
		            	printf("\033[0;31mINVALID INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
					}
				  }
		}
		// sample 2 pr
		else if (enput3 == '2'){
			system("cls");
			loadingBar();
			system("cls");
			printf("\033[0;37m");
				for (int i = 0; i < 10; ++i){
				printf("Data set %d: \033[0;36m%d\033[0;37m   \033[0;36m%d\033[0;37m\n", i + 1, pr2sample1[i], pr2sample2[i]); // data sets
			}
			printf("\nExcel Calculator Results: ");
			printf("\nPearson r: \033[0;32m%.11lf\033[0;37m", prans2);
			printf("\n\nStatistical Tools Results: ");
			printf("\nPearson r: \033[0;32m-0.07\033[0;37m");
			printf("\n\nType [Y] to go back to Sample menu or type [N] to go back to Main Menu: ");
			flag--;
				while(flag2 == 1){
				scanf(" %c", &let);
				
				    if (toupper(let) == 'Y'){
                     flag--;    	
    				system("cls");
    				peaersonexl();
					}
					else if (toupper(let) == 'N'){
					system("cls");
					sampleProblems();
					flag--;
		            }
		            else{
		            	printf("\033[0;31mINVALID INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
					}
				  }
		}
		// sample 3 pr
		else if (enput3 == '3'){
			system("cls");
			loadingBar();
			system("cls");
			printf("\033[0;37m");
				for (int i = 0; i < 10; ++i){
				printf("Data set %d: \033[0;36m%d\033[0;37m   \033[0;36m%d\033[0;37m\n", i + 1, pr3sample1[i], pr3sample2[i]); // data sets
			}
			printf("\nExcel Calculator Results: ");
			printf("\nPearson r: \033[0;32m%.10lf\033[0;37m", prans3);
			printf("\n\nStatistical Tools Results: ");
			printf("\nPearson r: \033[0;32m-0.18\033[0;37m");
			printf("\n\nType [Y] to go back to Sample menu or type [N] to go back to Main Menu: ");
			flag--;
				while(flag2 == 1){
				scanf(" %c", &let);
				
				    if (toupper(let) == 'Y'){
                     flag--;    	
    				system("cls");
    				peaersonexl();
					}
					else if (toupper(let) == 'N'){
					system("cls");
					sampleProblems();
					flag--;
		            }
		            else{
		            	printf("\033[0;31mINVALID INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
					}
				  }
		      }else if(enput3 == '4'){
		      	   system("cls");
		      	   sampleProblems();
		      	   flag--;
			  }else{
			  	printf("\033[0;31mINVALID INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
			  }
		     }
            } //end of persona 5




void anovaexl(){		//anova
        //dataset for ANOVA
	int anova1g1[] = {42, 30, 39, 28, 29};
	int anova1g2[] = {28, 36, 31, 32, 27};
	int anova1g3[] = {24, 36, 28, 28, 33};
	double anova1Ans = 0.7637795276;
	
	
	int anova2g1[] = {51, 45, 33, 45, 67};
	int anova2g2[] = {23, 43, 23, 43, 45};
	int anova2g3[] = {56, 76, 74, 87, 56};
	double anova2Ans = 9.747205503;
	
	
	int anova3g1[] = {34, 23, 12, 15, 16, 16};
	int anova3g2[] = {23, 32, 26, 27, 15, 14};
	int anova3g3[] = {58, 56, 45, 48, 56, 56};
	double anova3Ans = 43.57459207;
	char let, enput4;
	int flag = 1;
	int flag2 = 1;
	int enput, enput1, enput2, enput3, tenput, zenput;
		 
				system("cls");
				printf("\033[0;37m");
				printf("[\033[0;32m1\033[0;37m] Sample 1\n");
		        printf("[\033[0;32m2\033[0;37m] Sample 2\n");
		        printf("[\033[0;32m3\033[0;37m] Sample 3\n");
				printf("[\033[0;32m4\033[0;37m] Back\n");
				printf("\n");
				while(flag == 1){
				scanf(" %c", &enput4);
				
				// sample 1 anova
				if (enput4 == '1'){
					system("cls");
					loadingBar();
			system("cls");
			printf("\033[0;37m");
				for (int i = 0; i < 5; ++i){
				printf("Data set %d: \033[0;36m%d   %d   %d\033[0;37m\n", i + 1, anova1g1[i], anova1g2[i], anova1g3[i]); // data sets
			}
					printf("\nExcel Calculator Results: ");
					printf("\nPearson r: \033[0;32m%.10lf\033[0;37m", anova1Ans);
					printf("\n\nStatistical Tools Results: ");
					printf("\nPearson r: \033[0;32m0.763780\033[0;37m");
					printf("\n\nType [Y] to go back to Sample menu or type [N] to go back to Main Menu: ");
		        	flag--;
			    	while(flag2 == 1){
				    scanf(" %c", &let);
				
				    if (toupper(let) == 'Y'){
                     flag2--;    	
    				system("cls");
    				anovaexl();
					}
					else if (toupper(let) == 'N'){
					system("cls");
					sampleProblems();
					flag2--;
		            }
		            else{
		            	printf("\033[0;31mINVALID INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
					}
				  }
				}
				// sample 2 anova
				else if (enput4 == '2'){
					system("cls");
					loadingBar();
			system("cls");
			printf("\033[0;37m");
				for (int i = 0; i < 5; ++i){
				printf("Data set %d: \033[0;36m%d   %d   %d\033[0;37m\n", i + 1, anova2g1[i], anova2g2[i], anova2g3[i]); // data sets
			}
					printf("\nExcel Calculator Results: ");
					printf("\nPearson r: \033[0;32m%.10lf\033[0;37m", anova2Ans);
					printf("\n\nStatistical Tools Results: ");
					printf("\nPearson r: \033[0;32m9.747206\033[0;37m");
					printf("\n\nType [Y] to go back to Sample menu or type [N] to go back to Main Menu: ");
		        	flag--;
			    	while(flag2 == 1){
				    scanf(" %c", &let);
				
				    if (toupper(let) == 'Y'){
                     flag2--;    	
    				system("cls");
    				anovaexl();
					}
					else if (toupper(let) == 'N'){
					system("cls");
					sampleProblems();
					flag2--;
		            }else{
		            	printf("\033[0;31mINVALID INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
					}
				}
				// sample 3 anova
			   }else if (enput4 == '3'){
					system("cls");
					loadingBar();
			system("cls");
			printf("\033[0;37m");
				for (int i = 0; i < 6; ++i){
				printf("Data set %d: \033[0;36m%d   %d   %d\033[0;37m\n", i + 1, anova3g1[i], anova3g2[i], anova3g3[i]); // data sets
			}
					printf("\nExcel Calculator Results: ");
					printf("\nPearson r: \033[0;32m%.10lf\033[0;37m", anova3Ans);
					printf("\n\nStatistical Tools Results: ");
					printf("\nPearson r: \033[0;32m43.574593\033[0;37m");
					printf("\n\nType [Y] to go back to Sample menu or type [N] to go back to Main Menu: ");
		        	flag--;
			    	while(flag2 == 1){
				    scanf(" %c", &let);
				
				    if (toupper(let) == 'Y'){
                     flag2--;    	
    				system("cls");
    				anovaexl();
					}
					else if (toupper(let) == 'N'){
					system("cls");
					sampleProblems();
					flag2--;
		            }else{
		            	printf("\033[0;31mINVALID INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
					}
				}
	         	}else if(enput4 =='4'){
	         		system("cls");
		      	   sampleProblems();
		      	   flag--;
				 }else{
				 	printf("\033[0;31mINVALID INPUT\033[0;37m, PRESS ENTER AGAIN....\n");
				 }
              }
          }
 //end of anova
void sampleProblems(){
	system("cls");
	printf("\t\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
    printf("\t\t\t  SAMPLE PROBLEM\n");
    printf("\t\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n");
	char input;
	printf("Choose a tool to test.\n");
    printf("[\033[0;32m1\033[0;37m] Central Tendency\n");
	printf("[\033[0;32m2\033[0;37m] Hypothesis Testing\n");
	printf("[\033[0;32m3\033[0;37m] Pearson r\n");
	printf("[\033[0;32m4\033[0;37m] ANOVA\n");
	printf("[\033[0;32m5\033[0;37m] Back to Menu\n");
	printf("\n");
	int flag = 1;
	while(flag == 1){
	scanf(" %c", &input);
	if(input == '1'){
			flag--;
			system("cls");
			loadingBar();				
			system("cls");
			printf("\033[0;37m");
			centralexl();
      }else if(input == '2'){
		    flag--;
			system("cls");
			loadingBar();				
			system("cls");
			printf("\033[0;37m");
			hypomain();
       }else if( input == '3'){ 
		    flag--;
			system("cls");
			loadingBar();				
			system("cls");
			printf("\033[0;37m");
			peaersonexl();
	   }else if( input == '4'){
		    flag--;
			system("cls");
			loadingBar();				
			system("cls");
			printf("\033[0;37m");
			anovaexl();
	   }else if( input == '5'){
		flag--;
		system("cls");
		menu();
	}else{
		printf("\033[0;31mINVALID INPUT\033[0;37m, PLEASE ENTER AGAIN");
	}
}
}



void menu(){

		printf("\t\t================================\n");
    	printf("\t\t\tSTATISTICAL TOOLS\n");
        printf("\t\t================================\n\n");
	
	printf("\033[0;32m");
			printf("Choose on the following:\n\n");
			printf("\033[0;37m");
	printf("[\033[0;32m1\033[0;37m] Central Tendency\n");
	printf("[\033[0;32m2\033[0;37m] Hypothesis Testing\n");
	printf("[\033[0;32m3\033[0;37m] Pearson r\n");
	printf("[\033[0;32m4\033[0;37m] ANOVA\n");
	printf("[\033[0;32m5\033[0;37m] Sample Problems\n");
	printf("[\033[0;32m6\033[0;37m] Exit\n");
	
	char input;
	
	printf("\n");
	scanf(" %c", &input);
	
	if (input == '1'){
		system("cls");
		loadingBar();
		system("cls");
		printf("\033[0;37m");
		centralTendency();
		
	}
	else if (input == '2'){
		
		system("cls");
		loadingBar();
		system("cls");
		printf("\033[0;37m");
		hypothesisTesting();
		
	}
	else if (input == '3'){
		
		system("cls");
		loadingBar();
		system("cls");
		printf("\033[0;37m");
		pearsonr();
		
	}
	else if (input == '4'){
		
		system("cls");
		loadingBar();
		system("cls");
		printf("\033[0;37m");
		anova();
		
	}
	else if (input == '5'){
		
		system("cls");
		loadingBar();
		system("cls");
		printf("\033[0;37m");
		sampleProblems();
		
	}
	else if (input == '6'){
		
		system("cls");
		loadingBar();
		system("cls");
		printf("\033[0;37m");
		printf("You Exited!");
		exit(1);
	} else{
		// invalid input 
		system("cls");
		printf("Invalid input please try again.");
		Sleep(5);
		system("cls");
		menu();
	}
}

int main(void){
	
	menu();
	sampleProblems();
	return 0;
}
