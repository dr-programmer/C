#include <stdio.h>

struct Node {
    char firstname[20];
    struct Node *father;
    struct Node *mother;
    struct Node *marriedto;
};

int main()
{
    struct Node gmotherF = {"Ivanka", NULL, NULL, NULL};
    struct Node gfatherF = {"Peter", NULL, NULL, &gmotherF};
    gmotherF.marriedto = &gfatherF;
    struct Node gmotherM = {"Raisa", NULL, NULL, NULL};
    struct Node gfatherM = {"Yuriy", NULL, NULL, &gmotherM};
    gmotherM.marriedto = &gfatherM;
    struct Node mother = {"Oxana", &gfatherM, &gmotherM, NULL};
    struct Node father = {"Rosen", &gfatherF, &gmotherF, &mother};
    mother.marriedto = &father;
    struct Node me = {firstname: "Dariy", &father, &mother, NULL};

    return 0;
}