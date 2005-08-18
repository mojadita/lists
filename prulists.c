/* $Id: prulists.c,v 1.2 2005/08/18 09:18:39 luis Exp $
 * Author: Luis Colorado <Luis.Colorado@HispaLinux.ES>
 * Date: Mon Jul 18 17:53:02 CEST 2005
 *
 * Disclaimer:
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#define IN_PRULISTS_C

/* Standard include files */
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include "lists.h"

/* constants */

/* types */
struct nodo {
		int num;
		LNODE_T node;
};

LIST_DECLARE(lista_nodos);

/* prototypes */

/* variables */
static char PRULISTS_C_RCSId[]="\n$Id: prulists.c,v 1.2 2005/08/18 09:18:39 luis Exp $\n";

/* functions */
void printlist(void)
{
		LNODE_P p;

		printf("\n");
		LIST_FOREACH(p, &lista_nodos) {
				struct nodo *q = LIST_ELEMENT(p, struct nodo, node);
				printf("<%d>", q->num);
		} /* LIST_FOREACH */
		printf("\n");

} /* printlist */

/* main program */
int main (int argc, char **argv)
{
	printf(LISTS_H_PACKAGE_STRING":\n");
	for (;;) {
			struct nodo *p = LIST_ELEMENT(LIST_FIRST(&lista_nodos), struct nodo, node);
			struct nodo *n = malloc(sizeof (struct nodo));

			if (!n) {
					perror("malloc");
					exit(1);
			} /* if */
			n->num = random();
			LIST_APPEND(&lista_nodos, &n->node);

			if (!p || p == n) continue;

			if (n->num > p->num) {
					printlist();
					LIST_DELETE(LIST_FIRST(&lista_nodos));
					free(p);
			} /* if */
	} /* for */
} /* main */


/* $Id: prulists.c,v 1.2 2005/08/18 09:18:39 luis Exp $ */
