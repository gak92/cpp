# include <stdio.h>
# include <stdlib.h>

struct myArray
{
  int total_size;
  int used_size;
  int *ptr;
};

void CreateArray(struct myArray* a, int tSize, int uSize)
{
  // (*a).total_size = tSize;
  // (*a).used_size = uSize;
  // (*a).ptr = (int *) malloc(tSize * sizeof(int));

  a->total_size = tSize;
  a->used_size = uSize;
  a->ptr = (int *) malloc(tSize * sizeof(int));

}

void ShowArray(struct myArray* a)
{
  for(int i=0; i<a->used_size; i++)
  {
    printf("%d\n", (a->ptr)[i]);
  }

}

void SetArray(struct myArray* a)
{
  int n;
  for(int i=0; i<a->used_size; i++)
  {
    printf("Enter values: ");
    scanf("%d", &n);
    (a->ptr)[i] = n;
  }

}

int main()
{
  struct myArray marks;

  CreateArray(&marks, 10, 2);

  printf("Set Array: \n");
  SetArray(&marks);

  printf("Show Array\n");
  ShowArray(&marks);

  return 0;
}