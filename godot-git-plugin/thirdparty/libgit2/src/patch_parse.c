static int git_parse_err(const char *fmt, ...) GIT_FORMAT_PRINTF(1, 2);
static int git_parse_err(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	git_error_vset(GIT_ERROR_PATCH, fmt, ap);
	va_end(ap);

	return -1;
}

		return error;
	if (path->size > 0 && path->ptr[0] == '"' &&
	    (error = git_buf_unquote(path)) < 0)
		return error;
	if (!path->size)
		return git_parse_err("patch contains empty path at line %"PRIuZ,
				     ctx->parse_ctx.line_num);

	return 0;
	int error;
	if ((error = parse_header_path_buf(&path, ctx, header_path_len(ctx))) < 0)
		goto out;
out:
	git_buf_dispose(&path);
	if (patch->old_path) {
		error = git_parse_err("patch contains duplicate old path at line %"PRIuZ,
				      ctx->parse_ctx.line_num);
		goto out;
	}

	if (patch->new_path) {
		error = git_parse_err("patch contains duplicate new path at line %"PRIuZ,
				      ctx->parse_ctx.line_num);
	}
	if ((error = parse_header_path_buf(&new_path, ctx, ctx->parse_ctx.line_len - 1)) <  0)
		goto out;
	git__free((char *)patch->base.delta->new_file.path);
	patch->base.delta->new_file.path = NULL;
	git__free((char *)patch->base.delta->old_file.path);
	patch->base.delta->old_file.path = NULL;
	{ "--- "                , STATE_DIFF,       STATE_PATH,       parse_header_git_oldpath },
	{ "-- "                 , STATE_INDEX,      0,                NULL },
	int64_t num;
		int old_lineno, new_lineno, origin, prefix = 1;

		if (git__add_int_overflow(&old_lineno, hunk->hunk.old_start, hunk->hunk.old_lines) ||
		    git__sub_int_overflow(&old_lineno, old_lineno, oldlines) ||
		    git__add_int_overflow(&new_lineno, hunk->hunk.new_start, hunk->hunk.new_lines) ||
		    git__sub_int_overflow(&new_lineno, new_lineno, newlines)) {
			error = git_parse_err("unrepresentable line count at line %"PRIuZ,
					      ctx->parse_ctx.line_num);
			goto done;
		}
		GIT_ERROR_CHECK_ALLOC(line->content);
		line->content = git__strndup(ctx->parse_ctx.line, line->content_len);
		GIT_ERROR_CHECK_ALLOC(line->content);
	int64_t len;
		if (!encoded_len || !ctx->parse_ctx.line_len || encoded_len > ctx->parse_ctx.line_len - 1) {
	const char *old = patch->old_path ? patch->old_path : patch->header_old_path;
	const char *new = patch->new_path ? patch->new_path : patch->header_new_path;

	if (!old || !new)
		return git_parse_err("corrupt binary data without paths at line %"PRIuZ, ctx->parse_ctx.line_num);

	if (patch->base.delta->status == GIT_DELTA_ADDED)
		old = "/dev/null";
	else if (patch->base.delta->status == GIT_DELTA_DELETED)
		new = "/dev/null";

	    git_parse_advance_expected_str(&ctx->parse_ctx, old) < 0 ||
	    git_parse_advance_expected_str(&ctx->parse_ctx, " and ") < 0 ||
	    git_parse_advance_expected_str(&ctx->parse_ctx, new) < 0 ||
	    git_parse_advance_expected_str(&ctx->parse_ctx, " differ") < 0 ||
	    git_parse_advance_nl(&ctx->parse_ctx) < 0)
	else if (prefixed_old)
	else
		patch->base.delta->old_file.path = NULL;
	else if (prefixed_new)
	else
		patch->base.delta->new_file.path = NULL;