node ={}
 
def insert(x):
	p=root
	while 1:
		if p>x:
			if node[p]['left']==None:
				node[p]['left']=x
				node[x]={'left':None, 'right':None}
				return
 
			else:
				p=node[p]['left']
 
		elif p<x:
			if node[p]['right']==None:
				node[p]['right']=x
				node[x]={'left':None, 'right':None}
				return
 
			else:
				p=node[p]['right']
 
def post(x):
	if x==None:
		return
 
	post(node[x]['left'])
	post(node[x]['right'])
	print(x)
if __name__ == '__main__':
	root=int(input())
	node[root]={'left':None, 'right':None}
	while 1:
		try:
			x=int(input())
			insert(x)
		except:
			post(root)
			break