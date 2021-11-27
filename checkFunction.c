#include "checkFunction.h"
#include "candidate.h"
#include "employer.h"
#include <errno.h>
int IDCheck(char* ID)
{
	long longID;
	if (strlen(ID) != 9 && strlen(ID) != 8)//check the length
	{
		printf("Your ID isn't right!\n");
		return 0;
	}
	longID = atol(ID);
	if (IDCheckIFREAL(longID) == 0)
	{
		printf("Your ID isn't right!\n");
		return 0;
	}
	return 1;

}
int IDCheckIFREAL(long numid) //function "ID"
{
	long int num1, num2, num3, num4, num5, num6, num7, num8, num9, sum; // in this function i unpucked the id number that the user entered. and multiplide by the algoritem 1,2.
	num1 = (numid / 100000000) * 1;
	num2 = ((numid / 10000000) % 10) * 2;
	num3 = ((numid / 1000000) % 10) * 1;
	num4 = ((numid / 100000) % 10) * 2;
	num5 = ((numid / 10000) % 10) * 1;
	num6 = ((numid / 1000) % 10) * 2;
	num7 = ((numid / 100) % 10) * 1;
	num8 = ((numid / 10) % 10) * 2;
	num9 = (numid % 10) * 1;
	if (num1 >= 10 || num2 >= 10 || num3 >= 10 || num4 >= 10 || num5 >= 10 || num6 >= 10 || num7 >= 10 || num8 >= 10 || num9 >= 10) // in this case i checked if after i multiplied i get number bigger than 10 so i broke the number and and sum it.
	{
		num1 = (num1 / 10) + (num1 % 10);
		num2 = (num2 / 10) + (num2 % 10);
		num3 = (num3 / 10) + (num3 % 10);
		num4 = (num4 / 10) + (num4 % 10);
		num5 = (num5 / 10) + (num5 % 10);
		num6 = (num6 / 10) + (num6 % 10);
		num7 = (num7 / 10) + (num7 % 10);
		num8 = (num8 / 10) + (num8 % 10);
		num9 = (num9 / 10) + (num9 % 10);
	}
	sum = num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8 + num9; // here i check the sum of the numbers after the algoritem.
	if (sum % 10 == 0)// if the sum devied by 10 without remain so its proper id.
		return 1;
	else// else mean that the id is not proper.
		return 0;
}
int MailCheck(char* mail)
{
	int position = 0;
	int point = 0;
	int point2 = 0;
	int counter2 = 0;
	int counter3 = 0;
	int counter4 = 0;
	int i = 0;
	for (i = 0; i < strlen(mail); i++)
	{
		if (mail[i] == '@')
			counter3++;
		if (mail[i] == '.')
			counter4++;
	}
	if (counter3 != 1 || counter4 < 1)
	{
		printf("Mail not valid !\n");
		return 0;
	}
	i = 0;
	while (mail[i] != '@')
	{
		position++;
		i++;
	}
	i = 0;
	while (mail[i] != '@')
	{
		counter2++;
		i++;
	}
	while (mail[i] != '.')
	{
		counter2++;
		i++;
	}
	for (int i = 0; i < strlen(mail); i++)
	{
		if (mail[i] == '.')
			point++;
		if (mail[i] == '@')
			point2++;
	}
	if (position >= 3 && point >= 1 && point2 == 1 && position < counter2)
		return 1;
	else
	{
		printf("The mail is not valid !\n");
		return 0;
	}
}
int PasswordCheck(char* password)
{
	int i = 0;
	int countLower = 0, countUpper = 0, countSymbol = 0, countDigit = 0;
	for (int i = 0; i < strlen(password); i++)
	{
		if (password[i] >= 'A' && password[i] <= 'Z')
			countUpper++;
		if (password[i] >= 'a' && password[i] <= 'z')
			countLower++;
		if (password[i] >= '0' && password[i] <= '9')
			countDigit++;
		if (password[i] >= 32 && password[i] <= 47 || password[i] >= 58 && password[i] <= 64 || password[i] >= 92 && password[i] <= 96 || password[i] >= 123 && password[i] <= 126)
			countSymbol++;
	}
	if (countUpper > 0 && countLower > 0 && countDigit > 0 && countSymbol > 0 && strlen(password) >= 8)
	{
		return 1;
	}
	else
	{
		printf("The password does not match the conditions, try again !\n");
		return 0;
	}
}
int BirthCheck(int day, int month, int year)
{
	if (year < 1900)
	{
		printf("Not valid year !\n");
		return 0;
	}
	if (month < 1 || month >12)
	{
		printf("Not valid month !\n");
		return 0;
	}
	if (day < 1 || day>31)
	{
		printf("Not valid day !\n");
		return 0;
	}
	if (year % 4 == 0 && year & 100 != 0 || year % 400 == 0)
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day >= 1 && day <= 31)
			{
				return 1;
			}
			else
			{
				printf("birthdate not valid !\n");
				return 1;
			}
		}
		if (month == 2)
		{
			if (day >= 1 && day <= 29)
			{
				return 1;
			}
			else
			{
				printf("birthdate not valid !\n");
				return 0;
			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day >= 1 && day <= 30)
			{
				return 1;
			}
			else
			{
				printf("birthdate not valid !\n");
				return 0;
			}
		}


	}
	else
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day >= 1 && day <= 31)
			{
				return 1;
			}
			else
			{
				printf("birthdate not valid !\n");
				return 0;
			}
		}
		if (month == 2)
		{
			if (day >= 1 && day <= 28)
			{
				return 1;
			}
			else
			{
				printf("birthdate not valid !\n");
				return 0;
			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day >= 1 && day <= 30)
			{
				return 1;
			}
			else
			{
				printf("birthdate not valid !\n");
				return 0;
			}
		}
	}
}
int PhoneCheck(char* phone)
{
	if (phone[0] == '0' && phone[1] == '5' && strlen(phone) == 10)
		return 1;
	if (strlen(phone) != 10)
	{
		printf("The phone number must have 10 digits, try again !\n");
		return 0;
	}
	else
	{
		printf("The phone number must start with 05, try again !\n");
		return 0;
	}
}
int deleteline(char* fileName, int row)// delete the line from the file
{
	char buffer[2024];
	int numRow = 0, rc;
	char name[50] = "temp";
	FILE* fp = fopen(fileName, "r");
	strcat(name, fileName);
	FILE* temp = fopen(name, "w");
	if (!fp)
	{
		printf("Can't open file: %s\n", fileName);
		return 1;
	}
	if (!temp)
	{
		printf("Can't open file: %s\n", name);
		return 1;
	}
	else
	{
		while (fgets(buffer, 1024, fp))//copy all the line exept the line we want to delete
		{
			numRow++;
			if (row != numRow)
				fputs(buffer, temp);
		}
	}


	fclose(fp);

	rc = remove(fileName);
	if (rc != 0)
	{
		perror("remove");
		return 1;
	}
	fclose(temp);
	rc = rename(name, fileName);
	return 0;
}
int deleteJobLine(char* fileName, int serialNum)
{
	char num[50];
	sprintf(num, "%d", serialNum);
	char buffer[2024];
	int numRow = 0, rc;
	char name[50] = "temp";
	FILE* fp = fopen(fileName, "r");
	strcat(name, fileName);
	FILE* temp = fopen(name, "w");
	if (!fp)
	{
		printf("Can't open file: %s\n", fileName);
		return 1;
	}
	if (!temp)
	{
		printf("Can't open file: %s\n", name);
		return 1;
	}
	else
	{
		while (fgets(buffer, 1024, fp))
		{
			char tempbuf[1024];
			strcpy(tempbuf, buffer);
			if (strcmp(getfield(tempbuf, 1), num) != 0)
			{
				fprintf(temp, "%s", buffer);
			}
		}
	}


	fclose(fp);


	rc = remove("JOB_LIST_DATA.csv");
	if (rc != 0)
	{
		perror("remove");
		return 1;
	}
	fclose(temp);
	rc = rename(name, fileName);
	return 0;
}

int deleteJobLineFromCAND_NAME_CSVfile(char* fileName, int serialNum)
{
	char num[50];
	sprintf(num, "%d", serialNum);
	char buffer[2024];
	int numRow = 0, rc;
	char name[50] = "temp";
	FILE* fp = fopen(fileName, "r");
	strcat(name, fileName);
	FILE* temp = fopen(name, "w");
	if (!fp)
	{
		printf("Can't open file: %s\n", fileName);
		return 1;
	}
	if (!temp)
	{
		printf("Can't open file: %s\n", name);
		return 1;
	}
	else
	{
		while (fgets(buffer, 1024, fp))
		{
			char tempbuf[1024];
			strcpy(tempbuf, buffer);
			if (strcmp(getfield(tempbuf, 1), num) != 0)
			{
				fprintf(temp, "%s", buffer);
			}
		}
	}


	fclose(fp);


	rc = remove(fileName);
	if (rc != 0)
	{
		perror("remove");
		return 1;
	}
	fclose(temp);
	rc = rename(name, fileName);
	return 0;
}

int deleteFromSubAndFromPersonalcsvFile(char* fileName, int jobNumber)
{

	char* temp;
	char* temp2;
	char canName[MAXNAME];
	char buffer[2024];
	char ID[MAXNAME];
	int rc,check = 0, check2 = 0;
	//deleteFromSubAndFromPersonalcsvFile(char* fileName,int jobNumber)
	FILE* fp = fopen(fileName, "w");
	if (!fp) {
		// Error in file opening
		printf("Can't open file\n");
		return 1;
	}
	while (fgets(buffer, 1024, fp))
	{

		temp = _strdup(buffer);
		temp2 = _strdup(buffer);
		strcpy(ID, getfield(temp, 1));// geting the id.

		strcpy(canName, getfield(temp2, 2));// geting the name of canditate.
		strcat(canName, ID);
		strcat(canName, ".csv");
		if (findJobsubFile(canName) == 0)// if there a canditade_name_id.csv file.
		{
			check2 = deleteJobLineFromCAND_NAME_CSVfile(canName, jobNumber);
			if (check2 == 0)
			{
				printf("\nJob No.%d was deleted successfully from %s.csv file!\n", jobNumber, canName);
			}
			else
			{
				printf("\nThere was a problem to delete your job!\n");
				return 1;
			}

		}
		else
			continue;
	}
	fclose(fp);


	rc = remove(fileName);
	if (rc != 0)
	{
		perror("remove");
		return 1;
	}
	printf("\nSubmissions file was removed successfully!\n");
	return 0;
}

int fevoritsDelete(char* fileName,int jobNumber)
{
	char* temp3;
	char* temp4;
	char canName[MAXNAME];
	char buffer[2024];
	char ID[MAXNAME];
	int rc,check2 = 0;
	FILE* fpcand = fopen("Candidate_DATA.csv", "r");// to search for the fevorits
	if (!fpcand)
	{
		printf("Can't open file\n");
		return 1;
	}
	while (fgets(buffer, 1024, fpcand))
	{

		temp3 = _strdup(buffer);
		temp4 = _strdup(buffer);
		strcpy(ID, getfield(temp3, 1));// geting the id.
		strcpy(canName, getfield(temp4, 2));// geting the name of canditate.
		char name[MAXNAME] = "FAVORITEJOB";
		strcat(name, canName);
		strcat(name, ID);
		strcat(name, ".csv");
		if (findJobsubFile(name) == 0)
		{
			check2 = deleteJobLineFromCAND_NAME_CSVfile(name, jobNumber);
			if (check2 == 0)
			{
				printf("\nJob No.%d was deleted successfully from %s file!\n", jobNumber, name);
			}
			else
			{
				fclose(fpcand);
				printf("\nThere was a problem to delete your job!\n");
				return 1;
			}

		}
		else
			continue;
	}
	fclose(fpcand);
	return 0;
}



int findRightRowSerial(char* fileName, char* serial)
{//find the row by serial, returns the line nunber
	char* temp, buffer[2024];
	int column = 0, row = 0;
	FILE* fp = fopen(fileName, "r");
	if (!fp)
	{
		printf("Can't open file\n");
		return 1;
	}

	else
	{
		while (fgets(buffer, 1024, fp))//run until he find the row that matches the email
		{
			row++;
			if (strcmp("\n", buffer) == 0)
				break;
			temp = _strdup(buffer);
			if (strcmp(serial, getfield(temp, 1)) == 0)
			{
				fclose(fp);
				return row;
			}
		}
	}
	fclose(fp);
	return 1;
}
int findRightRow(char* fileName, char* email)
{//find the row by email, returns the line nunber
	char* temp, buffer[2024];
	int column = 0, row = 0;
	FILE* fp = fopen(fileName, "r");
	if (!fp)
	{
		printf("Can't open file\n");
		return 1;
	}

	else
	{
		while (fgets(buffer, 1024, fp))//run until he find the row that matches the email
		{
			row++;
			if (strcmp("\n", buffer) == 0)
				break;
			temp = _strdup(buffer);
			if (strcmp(email, getfield(temp, 4)) == 0)
			{
				fclose(fp);
				return row;
			}
		}
	}
	fclose(fp);
	return 1;
}
int findRightRowPass(char* fileName, char* pass)
{//find the row by password, returns the line nunber
	char buffer[2024],*temp;
	int column = 0, row = 0;
	FILE* fp = fopen(fileName, "r");
	if (!fp)
	{
		printf("Can't open file\n");
		return -1;
	}
	else
	{
		while (fgets(buffer, 1024, fp))//run until he find the row that matches the email
		{
			row++;
			temp = _strdup(buffer);
			if (strcmp(getfield(temp, 5), pass) == 0)
			{
				fclose(fp);
				return row;
			}
		}
	}
	fclose(fp);
	return -1;
}
int CheckLower(char* city)
{
	int count = 0, i = 0, countSpace = 0, countSymbol = 0;

	for (i; i < strlen(city); i++)
	{
		if (city[i] >= 'a' && city[i] <= 'z')
		{
			count++;
		}
		if (city[i] == ' ')
		{
			countSpace++;
		}
		if (city[i] > 32 && city[i] <= 47 || city[i] >= 58 && city[i] <= 64 || city[i] >= 92 && city[i] <= 96 || city[i] >= 123 && city[i] <= 126)
		{
			countSymbol++;
		}


	}
	if (count == strlen(city) - countSpace - countSymbol)
		return 1;
	else
	{
		printf("Enter the city only in lowercase : ");
		return 0;
	}

}
const char* getfield(char* line, int column)
{
	const char* value;
	for (value = strtok(line, ",");
		value && *value;
		value = strtok(NULL, ",\n"))
	{
		if (!--column)
			return value;
	}
	return NULL;
}
int ifExists(char* fileName, char* name, int column)// check every field in the column if the name value exists
{
	char buffer[MAXBUFFER],*temp;
	FILE* fp = fopen(fileName, "r");
	if (!fp)
	{
		return 1;
	}

	while (fgets(buffer, 2024, fp))
	{
		temp = _strdup(buffer);
		if (strcmp(getfield(temp, column), name) == 0)
		{
			fclose(fp);
			return 0;

		}
	}
	fclose(fp);
	return 1;
}
int sortFile(char* fileName, int column)
{
	char buffer[MAXBUFFER];
	char name[MAXNAME] = "temp";
	char* temp2;
	int mone = lastSerial();// check for the last serial
	int counter = 1, rc;
	strcat(name, fileName);
	int row = 0, run = 0;
	FILE* pf = fopen(fileName, "r");
	if (!pf)
	{
		printf("can't open the file: %s", fileName);
		return 1;
	}
	FILE* temp = fopen(name, "w");
	if (!temp)
	{
		printf("can't open the file: %s", name);
		return 1;
	}
	fgets(buffer, 2024, pf);
	fprintf(temp, "%s", buffer);
	while (counter <= mone)
	{
		while (fgets(buffer, 2024, pf))
		{
			temp2 = _strdup(buffer);
			if (atoi(getfield(temp2, 1)) == counter)
			{
				fprintf(temp, "%s", buffer);
				break;
			}
		}
		counter++;
		rewind(pf);
	}
	fclose(pf);
	rc = remove(fileName);
	if (rc != 0)
	{
		perror("remove");
		return 1;
	}
	fclose(temp);
	rc = rename(name, fileName);
	return 0;
}

int countNumLine(char* fileName)
{
	char buffer[MAXBUFFER];
	FILE* pf = fopen(fileName, "r");
	if (!pf)
	{
		printf("can't open the file: %s", fileName);
		return 1;
	}
	int mone = -1;
	while (fgets(buffer, 2024, pf))
	{
		mone++;
	}
	fclose(pf);
	return mone;

}

int sortFilefromendtostart(char* fileName, int column)
{
	char buffer[MAXBUFFER];
	char name[MAXNAME] = "temp";
	char* temp2;
	int mone = lastSerial();
	int counter = mone, rc;
	strcat(name, fileName);
	int row = 0, run = 0;
	FILE* pf = fopen(fileName, "r");
	if (!pf)
	{
		printf("can't open the file: %s", fileName);
		return 1;
	}
	FILE* temp = fopen(name, "w");
	if (!temp)
	{
		printf("can't open the file: %s", name);
		return 1;
	}
	fgets(buffer, 2024, pf);
	fprintf(temp, "%s", buffer);
	while (counter >= 0)
	{
		while (fgets(buffer, 2024, pf))
		{
			temp2 = _strdup(buffer);
			if (atoi(getfield(temp2, 1)) == counter)
			{
				fprintf(temp, "%s", buffer);
				break;
			}
		}
		counter--;
		rewind(pf);
	}
	fclose(pf);
	rc = remove(fileName);
	if (rc != 0)
	{
		perror("remove");
		return 1;
	}
	fclose(temp);
	rc = rename(name, fileName);
	return 0;
}

int lastSerial()
{
	int bigSerialNum = 0;
	char* value, buffer[2024];
	char* temp;


	FILE* JoblistdataF = fopen("JOB_LIST_DATA.csv", "r");
	if (JoblistdataF == NULL)
	{
		printf("Can't open file!");
		return;
	}


	while (fgets(buffer, 1024, JoblistdataF))//run to the end.
	{
		temp = _strdup(buffer);
		if (bigSerialNum < atoi(getfield(temp, 1)))
			bigSerialNum = atoi(getfield(temp, 1));

	}
	fclose(JoblistdataF);
	return bigSerialNum;
}

int findJobsubFile(char* fileName)// file finder.
{
	char buffer[2024];
	FILE* fp = fopen(fileName, "r");
	if (!fp)
	{
		return 1;
	}
	fclose(fp);
	return 0;
}