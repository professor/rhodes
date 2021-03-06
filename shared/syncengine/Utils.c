/*
 *  Utils.c
 *  RhoSyncClient
 *
 *  Copyright (C) 2008 Lars Burgess. All rights reserved.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Utils.h"

/*
 * TODO: This should be included in stdlib.h?
 */
char* itoa (int n) {
	char* result = malloc(17);
	sprintf(result, "%d", n);
	return result;
}

/* Allocate a string based on size of data */
char* str_assign(char* data) {
	if (data) {
		int len = strlen(data);
		char* a = malloc(len+1);
		strcpy(a,data);
		return a;
	}
	return NULL;
}

/* Use DJBHash function to generate temp object id */
unsigned int DJBHash(char* str, unsigned int len) {
	unsigned int hash = 5381;
	unsigned int i = 0;
	
	for(i = 0; i < len; str++, i++) {
		hash = ((hash << 5) + hash) + (*str);
	}
	return hash;
}