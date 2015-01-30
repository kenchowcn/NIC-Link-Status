/*
 * 2014-12-1:build by ken<http://kenchowcn.com>
 */

#include<stdio.h>
#include<unistd.h>

/*
 * @ifname: NIC name 
 * @linked_field: when the NIC linked context
 * @return: 0:not linked, 1:linked, -1: error
 */
int nic_link_status(char *if_name, char *linked_field)
{
	int status = 0; /* unlinked */
	char buff[20] = {0}, cmd[30] = {0};
	FILE *fp = NULL;

	if ((NULL == if_name) || (NULL == linked_field))
		return -1;

	sprintf(cmd, "ifconfig %s | grep %s", if_name, linked_field);

	if (NULL == (fp = popen(cmd, "r")))
		return -1; /* It could be the ifname not exist. */

	if (0 < fread(buff, sizeof(char), sizeof(buff)-1, fp))
		status = 1; /* linked */
	
	fclose(fp);

	return status;
}

int main()
{
	if (0<nic_link_status("en0", "active"))
		printf("Status: linked. \r\n");
	else
		printf("Status: not linked, or NIC name error.\r\n");

	return 0;
}
