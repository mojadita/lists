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
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <dirent.h>
#include "lists.h"

/* constants */
#define FMT(X) __FILE__":%d:%s: " X, __LINE__, __func__

/* types */
struct nodo {
		char *name;
		LNODE_T node;
};

LIST_DECLARE(lista_nodos);

/* prototypes */

/* variables */
static char PRULISTS_C_RCSId[]="\n$Id: prulists.c,v 1.2 2005/08/18 09:18:39 luis Exp $\n";

/* main program */
int main (int argc, char **argv)
{
    struct nodo *p;
    LNODE_P it;
    int i;

    for (i = 1; i < argc; i++) {
        struct nodo *p = malloc(sizeof (struct nodo));
        p->name = strdup(argv[i]);
        if (!p || !p->name) {
            fprintf(stderr, FMT("malloc: %s(errno = %d)\n"),
                    strerror(errno), errno);
            exit(EXIT_FAILURE);
        }
        LIST_INIT(&p->node);
        printf(FMT("añadiendo [%s]\n"), p->name);
        //LIST_APPEND_ELEMENT(&lista_nodos, p, struct nodo, node);
        LIST_APPEND(&lista_nodos, &p->node);
    }
    LIST_FOREACH(it, &lista_nodos) {
        p = LIST_ELEMENT(it, struct nodo, node);
        printf(FMT("RECORRIENDO [%s]\n"), p->name);
    }
} /* main */


/* $Id: prulists.c,v 1.2 2005/08/18 09:18:39 luis Exp $ */
