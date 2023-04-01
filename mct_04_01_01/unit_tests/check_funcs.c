#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

START_TEST(test_push)
{
	queue_t *my_queue = NULL;
	init_queue(&my_queue);
	push(my_queue, 1);
	
	queue_t *needed_queue = NULL;
	init_queue(&needed_queue);
	needed_queue->stack1 = malloc(sizeof(stack_t));
	needed_queue->stack1->data = 1;
	
	int code = 0;
	if (my_queue->stack1->data != needed_queue->stack1->data)
		code = 1;
	
	free(needed_queue->stack1);
	ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_pop)
{
	queue_t *my_queue = NULL;
	init_queue(&my_queue);
	my_queue->stack1 = malloc(sizeof(stack_t));
	my_queue->stack1->data = 1;
	
	int num;
	pop(my_queue, &num);
	
	free_queue(my_queue);
	ck_assert_int_eq(num, 1);
}
END_TEST

Suite* funcs_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("tests");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_push);
	tcase_add_test(tc_pos, test_pop);
    suite_add_tcase(s, tc_pos);

    return s;
}

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = funcs_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
