#include<stdio.h>
void main() 
{
    printf("\t\tWelcome To Blue Plates\n");
	printf("Press Enter to display Menu : ");
	getchar();
	printf("Item\t\t\t\t price \n");
	printf("\nSOUP:\n");
	printf("\n1.Hot & Sour\t\t\tRs.%d\n2.Veg Manchow\t\t\tRs.%d\n3.Sweet Corn\t\t\tRs.%d\n\nNon-veg Soup \n\n4.Chicken Hot & Sour\t\tRs.%d\n5.Chicken Manchow\t\tRs.%d\n6.Chicken sweet corn\t\tRs.%d\n\nTandooriSnacks :\n\n7.Paneer Tikka\t\t\tRs.%d\n8.Tandoori chaap\t\tRs.%d\n",80,80,90,110,110,120,180,155);
	printf("9.Tandoori Malai chaap\t\tRs.%d\n10.Hara Bhara kabab\t\tRs.%d\n11.Chicken Tikka\t\tRs.%d\n12.Murg Malai Tikka\t\tRs.%d\n13.Tandoori chicken\t\tRs.%d\n14.Chicken Wings\t\tRs.%d\n15.Afghani Chicken Tikka\tRs.%d\n16.Tandoori Afghani Chicken\tRs.%d\n",180,160,230,260,350,220,260,400);
	printf("\nChinese Starters : \n\n17.Veg Spring Rolls\t\tRs.%d\n18.Honey Chilli Potato\t\tRs.%d\n19.Crispy Corn\t\t\tRs.%d\n20.Veg Manchuria(DRY)\t\tRs.%d\n21.Szechwan Chicken\t\tRs.%d\n22.Chilli Chicken\t\tRs.%d\n23.ChickenLollipop\t\tRs.%d\n24.Drums of Heaven\t\tRs.%d\n",150,150,180,160,300,300,220,240);
	int items_no[24]={80,80,90,110,110,120,180,155,180,160,230,260,350,220,260,400,150,150,180,160,300,300,220,240};
	int total_items;
	int items_no1[24];
	char c_name[50];
	printf("Enter the name of the customer : ");
	scanf("%s",c_name);
	long int phone;
	printf("Enter Mobile Number : ");
	scanf("%ld",&phone);
	printf("Enter total number of items : ");
	scanf("%d",&total_items);
	//printf("items_no: %d\n",items_no[1]);
	int i=0,j=0,k=0,total=0,add=0;
	int items[total_items],quantity;
	while(i<total_items) 
	{
		printf("Enter item number : ");
		scanf("%d",&items[i]);
		if(items[i]>24 || items[i]<1) 
		{
			printf("Invalid Item Number!!!\n");
			quantity=0;
		}
		else 
		{
			printf("Enter Quantity : ");
			scanf("%d",&quantity);
			if(quantity<=total_items) {
		      	if(quantity>1) 
			    {
				    for(j=i+1;j<=i+quantity;j++) 
				    {
					    items[j]=items[i];
				    }
		    	}
			}
			else 
			{
			    printf("Enter valid Quantity\n");
			}
			switch(items[i]) 
			{
				case 1:
					total=total+(80*quantity);
					items_no1[k]=quantity;
					break;
				case 2:
					total=total+(80*quantity);
					items_no1[k]=quantity;
					break;
				case 3:
					total+=(90*quantity);
					items_no1[k]=quantity;
					break;
				case 4:
					total+=(110*quantity);
					items_no1[k]=quantity;
					break;
				case 5:
					total+=(110*quantity);
					items_no1[k]=quantity;
					break;
				case 6:
					total+=(120*quantity);
					items_no1[k]=quantity;
					break;
				case 7:
					total+=(180*quantity);
					items_no1[k]=quantity;
					break;
				case 8:
					total+=(155*quantity);
					items_no1[k]=quantity;
					break;
				case 9:
					total+=(180*quantity);
					items_no1[k]=quantity;
					break;
				case 10:
					total+=(160*quantity);
					items_no1[k]=quantity;
					break;
				case 11:
					total+=(230*quantity);
					items_no1[k]=quantity;
					break;
				case 12:
					total+=(260*quantity);
					items_no1[k]=quantity;
					break;
				case 13:
					total+=(350*quantity);
					items_no1[k]=quantity;
					break;
				case 14:
					total+=(220*quantity);
					items_no1[k]=quantity;
					break;
				case 15:
					total+=(260*quantity);
					items_no1[k]=quantity;
					break;
				case 16:
					total+=(400*quantity);
					items_no1[k]=quantity;
					break;
				case 17:
					total+=(150*quantity);
					items_no1[k]=quantity;
					break;
				case 18:
					total+=(150*quantity);
					items_no1[k]=quantity;
					break;
				case 19:
					total+=(180*quantity);
					items_no1[k]=quantity;
					break;
				case 20:
					total+=(160*quantity);
					items_no1[k]=quantity;
					break;
				case 21:
					total+=(300*quantity);
					items_no1[k]=quantity;
					break;
				case 22:
					total+=(300*quantity);
					items_no1[k]=quantity;
					break;
				case 23:
					total+=(220*quantity);
					items_no1[k]=quantity;
					break;
				case 24:
					total+=(240*quantity);
					items_no1[k]=quantity;
					break;
				default:
					total+=0;
					break;
			}
		}
		i=i+quantity;
		k++;
		add+=quantity;
	}
	for(i=k;i<total_items;i++) {
	    items_no1[i]=0;
	}
	int toi=total_items;
	for(i=0;i<total_items;i++) {
	    for(j=i+1;j<total_items;j++) {
	        if(items[i]==items[j]) {
	            for(k=j;k<total_items;k++) {
	                items[k]=items[k+1];
	            }
	            total_items--;
	            j--;
	        }
	    }
	}
	float sum=total;
	sum+=0.18*total;
	j=0;
	k=0;
	if(add>toi) {
	    printf("Invalid!!! Error!!!\n");
	}
	else {
    	printf("\n\n\n");
    	printf("/------------------------------------------------------------------/\n");
    	printf("Customer Name : %s\n",c_name);
    	printf("Mobile Number : %ld\n",phone);
    	printf("/------------------------------------------------------------------/\n");
    	printf("Item No.\t\t\tQuantity\t\tPrice\n");
    	for(i=0;i<total_items;i++) {
    	    switch(items[i]) {
    	        case 1:
    	            printf("Hot & Sour Soup\t\t\t");
    	            k=1;
    	            break;
    	        case 2: 
    	            printf("Veg Manchow Soup\t\t");
    	            k=2;
    	            break;
    	        case 3:
    	            printf("Sweet Corn Soup\t\t\t");
    	            k=3;
    	            break;
    	        case 4:
    	            printf("Chicken Hot & Sour Sour\t\t");
    	            k=4;
    	            break;
    	        case 5:
    	            printf("Chicken Manchow Soup\t\t");
    	            k-5;
    	            break;
    	        case 6:
    	            printf("Chicken Sweet Corn Soup\t\t");
    	            k=6;
    	            break;
    	        case 7:
    	            printf("Paneer Tikka\t\t\t");
    	            k=7;
    	            break;
    	        case 8:
    	            printf("Tandoori Chaap\t\t\t");
    	            k=8;
    	            break;
    	        case 9:
    	            printf("Tandoori Malai Chaap\t\t");
    	            k=9;
    	            break;
    	        case 10:
    	            printf("Hara Bhara Kebab\t\t");
    	            k=10;
    	            break;
    	        case 11:
    	            printf("Chicken Tikka\t\t\t");
    	            k=11;
    	            break;
    	        case 12:
    	            printf("Murg Malai Tikka\t\t");
    	            k=12;
    	            break;
    	        case 13:
    	            printf("Tandoori Chicken\t\t");
    	            k=13;
    	            break;
    	        case 14:
    	            printf("Chicken Wings\t\t\t");
    	            k=14;
    	            break;
    	        case 15:
    	            printf("Afghani Chicken Tikka\t\t");
    	            k=15;
    	            break;
    	        case 16:
    	            printf("Tandoori Afghani Chicken\t");
    	            k=16;
    	            break;
    	        case 17:
    	            printf("Veg. Spring Rolls\t\t");
    	            k=17;
    	            break;
    	        case 18:
    	            printf("Honey Chilli Potato\t\t");
    	            k=18;
    	            break;
    	        case 19:
    	            printf("Crispy Corn\t\t\t");
    	            k=19;
    	            break;
    	        case 20:
    	            printf("Veg. Manchurian\t\t\t");
    	            k=20;
    	            break;
    	        case 21:
    	            printf("Szechwan Chicken\t\t");
    	            k=21;
    	            break;
    	        case 22:
    	            printf("Chilly Chicken Dry\t\t");
    	            k=22;
    	            break;
    	        case 23:
    	            printf("Chicken Lollipop\t\t");
    	            k=23;
    	            break;
    	        case 24:
    	            printf("Drums Of Heaven\t\t\t");
    	            k=24;
    	            break;
    	        default:
    	            printf("Invalid!!!");
    	            break;
    	    }
    	    printf("%d\t\t\t%d\n",items_no1[j],items_no[k-1]*items_no1[j]);
    	    j++;
    	}
    	printf("GST Amount\t\t\t\t\t\t:%f\n",0.18*total);
    	printf("___________________________________________________________________\n");
    	printf("Total\t\t\t\t\t\t\t:%.2f\n",sum);
    	printf("___________________________________________________________________\n");
    	printf("\nEnjoy your Food\n\nThank you for Visiting\n");
	}
}
