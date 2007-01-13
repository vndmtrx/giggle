/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * Copyright (C) 2007 Imendio AB
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GIGGLE_REVISION_H__
#define __GIGGLE_REVISION_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define GIGGLE_TYPE_REVISION            (giggle_revision_get_type ())
#define GIGGLE_REVISION(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GIGGLE_TYPE_REVISION, GiggleRevision))
#define GIGGLE_REVISION_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass), GIGGLE_TYPE_REVISION, GiggleRevisionClass))
#define GIGGLE_IS_REVISION(obj)	        (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GIGGLE_TYPE_REVISION))
#define GIGGLE_IS_REVISION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GIGGLE_TYPE_REVISION))
#define GIGGLE_REVISION_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GIGGLE_TYPE_REVISION, GiggleRevisionClass))

#define GIGGLE_TYPE_REVISION_TYPE       giggle_revision_type_get_type ()

typedef struct _GiggleRevision      GiggleRevision;
typedef struct _GiggleRevisionClass GiggleRevisionClass;
typedef struct _GiggleBranchInfo    GiggleBranchInfo;

typedef enum {
	GIGGLE_REVISION_BRANCH,
	GIGGLE_REVISION_MERGE,
	GIGGLE_REVISION_COMMIT
} GiggleRevisionType;

struct _GiggleRevision {
	GObject             parent_instance;
};

struct _GiggleRevisionClass {
	GObjectClass parent_class;
};

GType              giggle_revision_get_type          (void);
GType              giggle_revision_type_get_type     (void);
GiggleRevision *   giggle_revision_new_commit        (const gchar      *sha,
						      GiggleBranchInfo *branch);
GiggleRevision *   giggle_revision_new_branch        (const gchar      *sha,
						      GiggleBranchInfo *old,
						      GiggleBranchInfo *new);
GiggleRevision *   giggle_revision_new_merge         (const gchar      *sha,
						      GiggleBranchInfo *to,
						      GiggleBranchInfo *from);
void               giggle_revision_validate          (GtkTreeModel     *model,
						      gint              n_column);
GiggleRevisionType giggle_revision_get_revision_type (GiggleRevision   *revision);
GdkColor *         giggle_revision_get_color         (GiggleRevision   *revision,
						      GiggleBranchInfo *branch_info);
GiggleBranchInfo * giggle_revision_get_branch1       (GiggleRevision   *revision);
GiggleBranchInfo * giggle_revision_get_branch2       (GiggleRevision   *revision);

const gchar      * giggle_revision_get_sha           (GiggleRevision   *revision);
const gchar      * giggle_revision_get_author        (GiggleRevision   *revision);
const gchar      * giggle_revision_get_date          (GiggleRevision   *revision);
const gchar      * giggle_revision_get_short_log     (GiggleRevision   *revision);
const gchar      * giggle_revision_get_long_log      (GiggleRevision   *revision);

GiggleBranchInfo * giggle_branch_info_new            (const gchar      *name);
void               giggle_branch_info_free           (GiggleBranchInfo *info);

G_END_DECLS

#endif /* __GIGGLE_REVISION_H__ */
