#include <stdio.h>
#include <stdlib.h>

#define FIXED_BUFF_LEN 32

struct fixed_buff {
	uint8_t data[FIXED_BUFF_LEN];
	unsigned int data_len;

	struct fixed_buff *next;
};

/**
 * @param : none
 * @return: newly allocated struct fixed_buff pointer
 */
struct fixed_buff *fixed_buff_alloc(void)
{
	struct fixed_buff *new = (struct fixed_buff *)malloc(sizeof(struct fixed_buff));
	return new;
}

/**
 * @param data_len: the length of the data returned
 * @return: the data from the stream, NULL when stream is done
 */
uint8_t* stream_get(struct stream *s, unsigned int *data_len);

/**
 * @return: head of the fixed_buff list
 */
struct fixed_buff *build_fixed_buff_list(struct stream *s)
{
	uint8_t *curr_data;
	unsigned int curr_data_len;

	struct fixed_buff *head = NULL;
	struct fixed_buff *temp;
	struct fixed_buff *new;

	while ((curr_data = stream_get(s, &curr_data_len)) {

		while (curr_data_len) {
			/** if we were consuming data and created list already */
			if (head) {
				// traverse the list first and check how much space is left for new stream
				temp = head;
				while (temp->next)
					temp = temp->next;	
				
				// any space available in earlier node utilise that
				if ((temp->data_len) + 1) < FIXED_BUFF_LEN) {
					for (int l = 0; l < (FIXED_BUFF_LEN - ((temp->data_len) + 1); l++) {
						temp->data[temp->data_len++] = *curr_data;
						curr_data++;
						curr_data_len--;
					}	
				}
			}

			if (curr_data_len) {

				new = fixed_buff_alloc();
				new->data_len = 0;
				new->next = NULL;
			
				if (curr_data_len >= FIXED_BUFF_LEN) {
					for (int i = 0; i < FIXED_BUFF_LEN; i++) {
						new->data[new->data_len++] = *curr_data;
						curr_data++;
						curr_data_len--;
					}
				} else if (curr_data_len <= (FIXED_BUFF_LEN - (new->data_len + 1))) {
					// fill up till this node can accommodate
					for (int i = (new->data_len + 1) ; i > 0; i--) {
						new->data[new->data_len++] = *curr_data;
						curr_data++;
						curr_data_len--;
					}
				} else {
					for (int i = curr_data_len; i > 0; i--) {
						new->data[new->data_len++] = *curr_data;
						curr_data++;
						curr_data_len--;
					}
				}

				if (head == NULL) {
					head = new;
				} else {
					temp = head;
					while (temp->next)
						temp = temp->next;
					temp->next = new;
				}
			}
		}
	}

	return head;
}

