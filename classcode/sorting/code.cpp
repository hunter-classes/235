

i=0; 
j=14;
x=65;
while (i <= j) {
  while (a[i] < x)
    i++;
  while (a[j] > x)
    j--;
  if (i <= j) {
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
    i++;
    j--;
      
  }
 }  
