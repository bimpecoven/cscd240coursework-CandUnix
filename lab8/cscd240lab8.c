
#include <stdio.h> 
int main()
{
int arr[] = { 200, 400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000}; 
int *ptr = arr;
/* This gives us an idea of the memory map */ 
printf("sizeof(ptr) %ld\n", sizeof(ptr) );
printf("sizeof(arr[0]) %ld\n", sizeof(arr[0]) );
printf("arr %p\n", arr); 
printf("ptr %p\n", ptr);
printf("arr[1] %p\n", &arr[1]); 
printf("arr[9] %p\n", &arr[9]); 
printf("&ptr %p\n", &ptr);
/* end memory map */


ptr++;
printf("*ptr %d\n", *ptr); 
printf("ptr %p\n", ptr);
// we talked about why we hate this but you need to understand *++ptr;
printf("*++ptr %d\n", *ptr);
printf("ptr %p\n", ptr);
//*ptr++;
printf("*ptr++ %d\n", *ptr); 
printf("ptr %p\n", ptr);
ptr = arr; // reset ptr
// fun with printf repeat last couple of commands printf("*++ptr %d\n", *++ptr);
printf("ptr %p\n", ptr);
printf("*ptr++ %d\n", *ptr++); 
printf("ptr %p\n", ptr);
ptr = arr; // reset ptr
*ptr += 1;
printf("*ptr %d\n", *ptr); 
printf("ptr %p\n", ptr);
printf("*(ptr+1) %d\n", *(ptr+1)); 
ptr = arr; // reset ptr
*(arr+2) = *ptr+100; 
printf("*(arr+2) %i\n", *(arr+2));
ptr = arr + 5;
printf("*ptr %d\n", *ptr); 
printf("ptr %p\n", ptr);
ptr = arr; // reset ptr
arr[2] = *(ptr + 5);
printf("arr[2] %d\n", arr[2]);
ptr = (arr + 10); printf("ptr %p\n", ptr); 
printf("*ptr %d\n", *ptr);

return 0; 
}// end main



