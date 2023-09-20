#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

struct recipe {
    char* name;
    char* ingredients;
    char* type;
};

struct recipe recipes[] = {
    {"Cheesy Ramen Noodles", "2 packs of ramen noodles\n2 cups of water\n1/4 cup of milk\n1/2 cup of shredded cheddar cheese\n1/4 cup of grated parmesan cheese\n1/4 tsp of garlic powder\nSalt and pepper to taste", "student"},
    {"Quesadilla Pizza", "4 tortillas\n1/2 cup of pizza sauce\n1/2 cup of shredded mozzarella cheese\n1/2 cup of chopped pepperoni\n1/4 cup of chopped green onions", "student"},
    {"Plov (Azerbaijani Rice Pilaf)", "2 cups of long-grain rice\n2 cups of water\n1/4 cup of vegetable oil\n1 large onion, chopped\n1 lb of lamb or beef, cut into bite-sized pieces\n2 carrots, grated\n1/4 cup of golden raisins\nSalt and pepper to taste", "azeri"},
    {"Dolma (Stuffed Vegetables)", "8-10 bell peppers or tomatoes\n1 lb of ground lamb or beef\n1 onion, chopped\n1/2 cup of long-grain rice\n1/4 cup of chopped fresh parsley\nSalt and pepper to taste\n2 cups of water", "azeri"},
    {"Coq au Vin (Chicken in Red Wine)", "4 chicken thighs\n4 chicken drumsticks\nSalt and pepper to taste\n4 slices of bacon, chopped\n1 onion, chopped\n2 garlic cloves, minced\n1/4 cup of all-purpose flour\n2 cups of red wine\n1 cup of chicken broth\n2 tbsp of tomato paste\n2 bay leaves\n1 tsp of dried thyme\n1 cup of sliced mushrooms\n1/4 cup of chopped fresh parsley", "french"},
    {"Ratatouille (Vegetable Stew)", "2 tbsp of olive oil\n1 onion, chopped\n3 garlic cloves, minced\n1 eggplant, chopped\n2 zucchinis, chopped\n1 red bell pepper, chopped\n1 yellow bell pepper, chopped\n2 tomatoes, chopped\n2 tbsp of tomato paste\n1 tsp of dried thyme\nSalt and pepper to taste\nChopped fresh basil for garnish", "french"}
};

void handle_signal(int signal)
{
    srand(time(NULL));
    int rand_index;

    switch (signal)
    {
        case SIGINT:
            rand_index = rand() % 2;
            printf("---------------------------------\n");
            printf("Received SIGINT. Here is a recipe for a %s:\n", recipes[rand_index].type);
            printf("Name: %s\n", recipes[rand_index].name);
            printf("Ingredients: %s\n", recipes[rand_index].ingredients);
            printf("---------------------------------\n");
            printf("\n\n");
            break;
        case SIGQUIT:
            rand_index = rand() % 2 + 2;
            printf("---------------------------------\n");
            printf("Received SIGQUIT. Here is a recipe for a %s:\n", recipes[rand_index].type);
            printf("Name: %s\n", recipes[rand_index].name);
            printf("Ingredients: %s\n", recipes[rand_index].ingredients);
            printf("---------------------------------\n");
            printf("\n\n");
            break;
        case SIGTERM:
            rand_index = rand() % 2 + 4;
            printf("---------------------------------\n");
            printf("Received SIGTERM. Here is a recipe for a %s:\n", recipes[rand_index].type);
            printf("Name: %s\n", recipes[rand_index].name);
            printf("Ingredients: %s\n", recipes[rand_index].ingredients);
            printf("---------------------------------\n");
            printf("\n\n");
            break;
    }

}

int main()
{
    pid_t pid = getpid();
    printf("Server process ID: %d\n", pid);

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    while (1)
    {
        sleep(1);
    }

    return 0;
}