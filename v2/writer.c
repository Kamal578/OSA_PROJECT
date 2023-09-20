#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h> // for strcpy()
#include "student.h"
#include "azeri.h"
#include "french.h"

#define MAX 10

// structure for message queue
struct mesg_buffer {
		long mesg_type;
		char mesg_text[500];
} message;

void cooking_recipe_writer(){
		key_t key;
		int msgid;

		printf("Enter the category of the recipe you want to read(1, 2, or 3): ");
		scanf("%ld", &message.mesg_type);		

		// ftok to generate unique key
		key = ftok("recipe", 65);

		// msgget creates a message queue
		// and returns identifier
		msgid = msgget(key, 0666 | IPC_CREAT);

		switch (message.mesg_type)
		{
		case 1:
			for (int j = 0; j < 2; j++)
			{

				strcpy(message.mesg_text, "2 packs of ramen noodles\n2 cups of water\n1/4 cup of milk\n1/2 cup of shredded cheddar cheese\n1/4 cup of grated parmesan cheese\n1/4 tsp of garlic powder\nSalt and pepper to taste\n");
				msgsnd(msgid, &message, sizeof(message), 0);
			}
			break;

		case 2:
			for (int j = 0; j < 2; j++)
			{
				strcpy(message.mesg_text, "2 cups of long-grain rice\n2 cups of water\n1/4 cup of vegetable oil\n1 large onion, chopped\n1 lb of lamb or beef, cut into bite-sized pieces\n2 carrots, grated\n1/4 cup of golden raisins\nSalt and pepper to taste\n");
				msgsnd(msgid, &message, sizeof(message), 0);
			}
			break;
			
		case 3:
			for (int j = 0; j < 2; j++)
			{
				strcpy(message.mesg_text, "4 chicken thighs\n4 chicken drumsticks\nSalt and pepper to taste\n4 slices of bacon, chopped\n1 onion, chopped\n2 garlic cloves, minced\n1/4 cup of all-purpose flour\n2 cups of red wine\n1 cup of chicken broth\n2 tbsp of tomato paste\n2 bay leaves\n1 tsp of dried thyme\n1 cup of sliced mushrooms\n1/4 cup of chopped fresh parsley\n");
				msgsnd(msgid, &message, sizeof(message), 0);
			}
			break;

		default:
				break;
		}
}


int main()
{
	// key_t key;
	// int msgid;

	// // ftok to generate unique key
	// key = ftok("recipe", 65);

	// // msgget creates a message queue
	// // and returns identifier
	// msgid = msgget(key, 0666 | IPC_CREAT);

	// message.mesg_type = 1;

	// while(1){
	// 	printf("Write Data : ");
	// 	fgets(message.mesg_text,MAX,stdin);

	// 	// msgsnd to send message
	// 	msgsnd(msgid, &message, sizeof(message), 0);

	// 	// display the message
	// 	printf("Data send is : %s \n", message.mesg_text);
	// }
	while(1)
		cooking_recipe_writer();


	return 0;
}