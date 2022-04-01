#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next_node;
}node;
typedef struct graph_vertex{
    node *Head;
}graph_head;
graph_head* CreateNewGraph(int n){
    graph_head *New = (graph_head*)malloc(n*sizeof(graph_head));
    for(int j = 0;j<n;j++) New[j].Head = NULL;
    return New;
}
int Deque(node **head){  //delete_end
    int i;
    if(*head!=NULL){
        node *record = (node*)malloc(sizeof(node));
        record = *head;
        if(record->next_node!=NULL){
            node *new = (node*)malloc(sizeof(node));
            while(record -> next_node != NULL){
                new = record;
                record = record -> next_node;
            }
            i = record->data;
            new -> next_node = NULL;
            free(record);
        }
        else{
            i = record->data;
            free(record);
            *head = NULL;
        }
    }
    return i;
}
void Enque(node **head,int item){  //Insert_begin
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = item;
    if(*head == NULL) new_node->next_node = NULL;
    else new_node->next_node = *head; 
    *head = new_node;
}
void BFS_Display(graph_head *Graph,int n){
    node *Queue,*tracer;
    int *visited = (int*)calloc(n,sizeof(int));
    Enque(&Queue,0);
    int d_number,number;
    printf("\nGraph - 0");
    visited[0] = 1;
    while(Queue!=NULL){
        d_number = Deque(&Queue);
        tracer = Graph[d_number].Head;
        while(tracer!=NULL){
            number = tracer->data;
            if(!visited[number]){
                printf(" %d",number);
                Enque(&Queue,number);
                visited[number] = 1;
            }
            tracer = tracer->next_node;
        }
    }
}
void Link(graph_head *Graph,int first,int second){
    Enque(&Graph[first].Head,second);
    Enque(&Graph[second].Head,first);
}
void Is_Connected(graph_head *Graph,int n){
    node *Queue,*tracer;
    int *visited = (int*)calloc(n,sizeof(int));
    Enque(&Queue,0);
    int d_number,number,count = 1;
    visited[0] = 1;
    while(Queue!=NULL){
        d_number = Deque(&Queue);
        tracer = Graph[d_number].Head;
        while(tracer!=NULL){
            number = tracer->data;
            if(!visited[number]){
                count++;
                Enque(&Queue,number);
                visited[number] = 1;
            }
            tracer = tracer->next_node;
        }
    }
    if(count == n) printf("\nConnected Graph");
    else printf("\nNot Connected ");
}
void CheckCycle(graph_head *Graph,int n){
    node *Queue,*tracer;
    int *visited = (int*)calloc(n,sizeof(int));
    for(int i = 0;i<n;i++) visited[i]--;
    Enque(&Queue,0);
    int d_number,number;
    visited[0] = 0;
    while(Queue!=NULL){
        d_number = Deque(&Queue);
        visited[d_number]++;   
        tracer = Graph[d_number].Head;
        while(tracer!=NULL){
            number = tracer->data;
            if(visited[number] == 0){
                printf("\nCycle Exists");
                return;
            }
            if(visited[number] == -1){
                Enque(&Queue,number);
                visited[number]++;
            }
            tracer = tracer->next_node;
        }
    }
    printf("\nCycle Doesn't Exists");
}
void Display(node **head){
    node *new_node = (node*)malloc(sizeof(node));
    new_node = *head;
    if(*head!=NULL){
    while(new_node != NULL){
        printf("%d -> ",new_node->data);
        new_node = new_node -> next_node;
    }
    }
}

void CheckPath(graph_head *Graph,int n,int first,int second){
    node *Queue,*tracer;
    int *visited = (int*)calloc(n,sizeof(int));
    int d_number,number;
    Queue = NULL;
    tracer = Graph[first].Head;
    Enque(&Queue,first);
    visited[first] = 1;
    while(Queue!=NULL){
        d_number = Deque(&Queue);
        tracer = Graph[d_number].Head;
        while(tracer!=NULL){
            number = tracer->data;
            if(!visited[number]){
                if(number == second){
                    printf("\nPath exists between %d and %d ",first,second);
                    return;
                } 
                Enque(&Queue,number);
                visited[number] = 1;
            }
            tracer = tracer->next_node;
        }
    }
    printf("\nPath Doesn't Exists between %d and %d",first,second);
}
int PathExistence(graph_head *Graph,int *predecessor,int n,int first,int second){
    node *Queue,*tracer;
    int *visited = (int*)calloc(n,sizeof(int));
    int d_number,number;
    Queue = NULL;
    tracer = Graph[first].Head;
    Enque(&Queue,first);
    visited[first] = 1;
    predecessor[first] = first;
    while(Queue!=NULL){
        d_number = Deque(&Queue);
        tracer = Graph[d_number].Head;
        while(tracer!=NULL){
            number = tracer->data;
            if(!visited[number]){
                predecessor[number] = d_number;
                if(number == second){
                    return 1;
                } 
                Enque(&Queue,number);
                visited[number] = 1;
            }
            tracer = tracer->next_node;
        }
    }
    return 0;
}
void SubShortestPath(graph_head *Graph,int *predecessor,int n,int first,int second){
    int *distance = (int*)calloc(n,sizeof(int));
    node *Queue,*tracer;
    int *visited = (int*)calloc(n,sizeof(int));
    Enque(&Queue,first);
    int d_number,number;
    visited[first] = 1;
    printf("\nShortest Path %d -> ",first);
    while(Queue!=NULL){
        d_number = Deque(&Queue);
        tracer = Graph[d_number].Head;
        while(tracer!=NULL){
            number = tracer->data;
            if(!visited[number]){
                distance[number] = distance[predecessor[number]]+1;
                if(number == second){
                    node *New_Queue;
                    New_Queue = NULL;
                    int track = second;
                    while(predecessor[track]!=track){
                        if(track!=second) Enque(&New_Queue,track);      
                        track = predecessor[track];
                    }
                    Display(&New_Queue);
                    printf("%d",second);
                    return;
                }
                Enque(&Queue,number);
                visited[number] = 1;
            }
            tracer = tracer->next_node;
        }
    }
}
void ShortestPath(graph_head *Graph,int first,int second,int n){
    int *predecessor = (int*)calloc(n,sizeof(int));
    for(int j = 0;j<n;j++) predecessor[j] = -1;
    if(PathExistence(Graph,predecessor,n,first,second)){
        SubShortestPath(Graph,predecessor,n,first,second);
    }else printf("\nPath didn't exist to calculate shortest path ");
}
int main(){
    graph_head *Graph;
    Graph = NULL;
    int n,item,choose,first,second;
    printf("Enter number of vertexes in Graph ");
    scanf("%d",&n);
    Graph = CreateNewGraph(n);
    printf("\nEnter 1 to Link two vetexes ");
    printf("\nEnter 2 to Display ");
    printf("\nEnter 3 to check Connectivity ");
    printf("\nEnter 4 for Existence of Cycle");
    printf("\nEnter 5 to check Path between two vertexes ");
    printf("\nEnter 6 for Shortest Path between two vertexes");
    printf("\nEnter 7 to Terminate");
    while(1){
        printf("\nChoose = ");
        scanf("%d",&choose);
        switch(choose){
            case 1:
                    printf("\nEnter two items to link ");
                    printf("\nFirst item = ");
                    scanf("%d",&first);
                    while(first>=n){
                        printf("\nVertex %d not in Graph ",first);
                        printf("\nFirst item = ");
                        scanf("%d",&first);
                    }
                    printf("\nSecond item = ");
                    scanf("%d",&second);
                    while(first>=n){
                        printf("\nVertex %d not in Graph ",second);
                        printf("\nSecond item = ");
                        scanf("%d",&second);
                    }
                    Link(Graph,first,second);
                    break;
            case 2: BFS_Display(Graph,n);
                    break;
            case 3: Is_Connected(Graph,n);
                    break;
            case 4: CheckCycle(Graph,n);
                    break;
            case 5: printf("\nEnter two items to Check Path ");
                    printf("\nFirst item = ");
                    scanf("%d",&first);
                    while(first>=n){
                        printf("\nVertex %d not in Graph ",first);
                        printf("\nFirst item = ");
                        scanf("%d",&first);
                    }
                    printf("\nSecond item = ");
                    scanf("%d",&second);
                    while(first>=n){
                        printf("\nVertex %d not in Graph ",second);
                        printf("\nSecond item = ");
                        scanf("%d",&second);
                    } 
                    CheckPath(Graph,n,first,second);
                    break;
            case 6: printf("\nEnter two items For shortest Path ");
                    printf("\nStarting Point = ");
                    scanf("%d",&first);
                    while(first>=n){
                        printf("\nVertex %d not in Graph ",first);
                        printf("\nStarting Point = ");
                        scanf("%d",&first);
                    }
                    printf("\nDestination Point = ");
                    scanf("%d",&second);
                    while(first>=n){
                        printf("\nVertex %d not in Graph ",second);
                        printf("\nDestination Point = ");
                        scanf("%d",&second);
                    }
                    ShortestPath(Graph,first,second,n);
                    break;
            case 7: exit(0);
        }
    }
    return 0;
}




