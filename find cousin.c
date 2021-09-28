#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	int elem;
	struct node *LC;
	struct node *RC;
}ctype, *BST;

void insertElem(int x, BST *trav)
{
	while (*trav != NULL && (*trav)->elem != x) {
		trav = (x > (*trav)->elem) ? &(*trav)->RC : &(*trav)->LC;
	}
	
	if (*trav == NULL) {
		*trav = (BST) malloc (sizeof(ctype));
		if (*trav != NULL) {
			(*trav)->elem = x;
			(*trav)->LC = NULL;
			(*trav)->RC = NULL;
		}
	}
}

BST populateBST(int arr[], int size)
{
	BST T;
	T = NULL;
	
	int i;
	for (i = 0; i < size; i++) {
		insertElem(arr[i], &T);
	}
	
	return T;
}

int getHeight(BST T, int person, int height)
{
    if (T == NULL)
        return 0;
    
    if (T->elem == person)
        return height;

    return T->elem < person ? getHeight(T->RC, person, height + 1) : getHeight(T->LC, person, height + 1);
}

void bfs(BST T)
{
    if (T == NULL)
        return;

    ctype queue[100] = {};
    int front = 0;
    int rear = -1;

    queue[++rear] = *T;
    while (front <= rear) {
        printf("%d ", queue[front].elem);
        if (queue[front].LC != NULL)
            queue[++rear] = *(queue[front].LC);
        if (queue[front].RC != NULL)
            queue[++rear] = *(queue[front].RC);
        
        ++front;
    }
}

void getCousinsOnSameLevel(BST T, int arr[], int *count, int person, int height)
{
    if (T == NULL || height < 0)
        return;

    if (T->LC && T->LC->elem == person || T->RC && T->RC->elem == person)
        return;

    if (height == 0) {
        arr[*count] = T->elem;
        (*count)++;
    }
    
    getCousinsOnSameLevel(T->LC, arr, count, person, height - 1);
    getCousinsOnSameLevel(T->RC, arr, count, person, height - 1);
}

void findCousins(BST T, int person)
{
    int arr[100] = {}, count = 0;
    int height = getHeight(T, person, 1);
    printf("\nheight: %d\n", height);

    // assumption:
    // height of 0 means person does not exist
    // height of 1 means it is a root
    // height of 2 means the direct children of root
    // doesnt exist in tree || no cousin(root) || no cousin(children of root - sibling)
    if (height <= 2)
        return;

    getCousinsOnSameLevel(T, arr, &count, person, height - 1);
    for (int i = 0; i < count; i++)
        printf("| %d | ", arr[i]);


}

int main()
{

    BST T;
	int arr[] = {10, 6, 5, 7, 14, 12, 18, 15, 1, 8, 13, 20};
	int size = 12;
	
	/**
	 *
     * given Tree
	 *				     10
	 *				   /      \
	 *				   6       14
	 *               /  \     /   \
	 *              5    7   12     18
	 *             /      \    \    /  \
	 *            1       8   13    15   20
     * 
     * given person = 1
     * 
     * 
     * output: 8 13 15 20
	 *
	 ****/
	
	T = populateBST(arr, size);

    bfs(T);
    findCousins(T, -10);


}