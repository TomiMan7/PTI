#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/list.h>
#include <linux/fdtable.h>

MODULE_DESCRIPTION ("");
MODULE_AUTHOR ("");
MODULE_LICENE ("");
static int
elso_init_module(void)
{
	struct task_struct *task;
	struct list_head *p;
	int i = 0;
		
	printk (KERN_NOTICE "Elso modul belep\n);
	
	list_for_each (p, current->task.next)
	{
		task = list_entry (p, struct task_struct, tasks);
		i = (task->files)->next_fd;
		printk (KERN_NOTICE "%s %i\n", task->comm,
			task->pid,i);
	}
	return 0;
}

static void
elso_exit_module(void)
{
	printk (KERN_NOTICE "Elso modul kilep\n");
}

module_init (elso_init_module);
module_exit (elso_exit_module);
