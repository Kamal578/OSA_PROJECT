#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h> 
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

		// ftok to generate unique key
		key = ftok("recipe", 65);

		// msgget creates a message queue
		// and returns identifier
		msgid = msgget(key, 0666 | IPC_CREAT);

		int signal = rand() % 3 + 2; // Generate a random signal number (2, 3, or 15)

		if(signal == 2 || signal == 3){
			printf("Sending signal %d\n", signal);
            sleep(1); // Wait for 1 second before sending the next signal
		}
		else{
			signal = 15;
			printf("Sending signal %d\n", signal);
			sleep(1); // Wait for 1 second before sending the next signal
		}

		message.mesg_type = signal;
		switch (message.mesg_type)
		{
		case 2:
			strcpy(message.mesg_text, "2 packs of ramen noodles\n2 cups of water\n1/4 cup of milk\n1/2 cup of shredded cheddar cheese\n1/4 cup of grated parmesan cheese\n1/4 tsp of garlic powder\nSalt and pepper to taste\n");
			msgsnd(msgid, &message, sizeof(message), 0);
			break;

		case 3:
			strcpy(message.mesg_text, "2 cups of long-grain rice\n2 cups of water\n1/4 cup of vegetable oil\n1 large onion, chopped\n1 lb of lamb or beef, cut into bite-sized pieces\n2 carrots, grated\n1/4 cup of golden raisins\nSalt and pepper to taste\n");
			msgsnd(msgid, &message, sizeof(message), 0);
			break;
			
		case 15:
			strcpy(message.mesg_text, "4 chicken thighs\n4 chicken drumsticks\nSalt and pepper to taste\n4 slices of bacon, chopped\n1 onion, chopped\n2 garlic cloves, minced\n1/4 cup of all-purpose flour\n2 cups of red wine\n1 cup of chicken broth\n2 tbsp of tomato paste\n2 bay leaves\n1 tsp of dried thyme\n1 cup of sliced mushrooms\n1/4 cup of chopped fresh parsley\n");
			msgsnd(msgid, &message, sizeof(message), 0);
			break;

		default:
				break;
		}


}


int main()
{
		for(int i=0;i<100;i++){
			cooking_recipe_writer();
		}

		return 0;
}