void
shiftviewclients(const Arg *arg)
{
	Arg shifted;
	Client *c;
	unsigned int tagmask = 0;

	for (c = selmon->clients; c; c = c->next) {
		tagmask = tagmask | c->tags;
	}

	shifted.ui = selmon->tagset[selmon->seltags];

	do {
		if (arg->i > 0) // left circular shift
			shifted.ui = (shifted.ui << arg->i)
			   | (shifted.ui >> (NUMTAGS - arg->i));
		else // right circular shift
			shifted.ui = (shifted.ui >> -arg->i)
			   | (shifted.ui << (NUMTAGS + arg->i));
	} while (tagmask && !(shifted.ui & tagmask));

	view(&shifted);
}

