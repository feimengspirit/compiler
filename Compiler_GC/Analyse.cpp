#include "ClassDecls.h"
#include "VarDecls.h"
#include "Program.h"
#include "ExtendsClassDecl.h"
#include "Analyse.h"



#define MAXSIZE 100

ClassDecl* cTable[MAXSIZE];		//存放已处理的类声明
int index;						//cTable当前位置


int compare_id(const string pre,const string next)
{
	return (pre.compare(next));
}
VarDecl* MaxVarDecl(VarDecls* vds)			//成员
{
	VarDecl *vd = vds->m_vd;
	vds = vds->m_vds;
	while(vds)
	{
		if(compare_id(vd->m_id->m_id.s,vds->m_vd->m_id->m_id.s)<0)
			vd = vds->m_vd;
		vds = vds->m_vds;
	}
	return vd;
}
MethodDecl* MaxMethodDecl(MethodDecls* mds)			//函数
{
	MethodDecl *md = mds->m_md;
	mds = mds->m_mds;
	while(mds)
	{
		if(compare_id(md->m_id->m_id.s,mds->m_md->m_id->m_id.s)<0)
			md = mds->m_md;
		mds = mds->m_mds;
	}
	return md;
}
int sort_id(Program*p)
{
	ClassDecls *cds = p->m_clsdcls;
	VarDecls *vds;
	MethodDecls *mds;
	VarDecl *vd;
	MethodDecl *md;
	while(cds)
	{
		vds = cds->m_clsdcl->m_vds;
		mds = cds->m_clsdcl->m_mds;
		vd = vds->m_vd;
		md = mds->m_md;
		if(vds->m_vds)					//排序成员声明
		{
			VarDecl *vnm = MaxVarDecl(vds->m_vds);
			if(compare_id(vd->m_id->m_id.s,vnm->m_id->m_id.s)>0)
			{
				NewToken tmp = vd->m_id->m_id;
				vd->m_id->m_id = vnm->m_id->m_id;
				vnm->m_id->m_id = tmp;
			}
		}
//************************************************************
		if(mds->m_mds)					//排序函数声明
		{
			MethodDecl *mdm = MaxMethodDecl(mds->m_mds);
			if(compare_id(md->m_id->m_id.s,mdm->m_id->m_id.s)>0)
			{
				NewToken tmp = md->m_id->m_id;
				md->m_id->m_id = mdm->m_id->m_id;
				mdm->m_id->m_id = tmp;
			}
		}

		cds = cds->m_clsdcls;
	}

	return 0;
}

//**********************消除extends相关函数**********************************

VarDecls* get_vardecls(string classname)
{
	VarDecls *vds;
	for(int i=0;i<index;i++)
	{
		if(classname.compare(cTable[i]->m_cnd->m_id->m_id.s)== 0)
		{
			vds = cTable[i]->m_vds;
			break;
		}
	}
	VarDecls *pre,*next,*head;
	Id *id = new Id(*(vds->m_vd->m_id));
	Type *t = new Type(*(vds->m_vd->m_type));
	pre = new VarDecls(new VarDecl(t,id),NULL);
	head = pre;
	vds = vds->m_vds;
	while(vds)
	{
		t = new Type(*(vds->m_vd->m_type));
		id = new Id(*(vds->m_vd->m_id));
		next = new VarDecls(new VarDecl(t,id),NULL);
		pre->m_vds = next;
		pre = next;
		vds = vds->m_vds;
	}
	return head;
}
MethodDecls* get_methoddecls(string classname)
{
	MethodDecls *mds;
	for(int i=0;i<index;i++)
	{
		if(classname.compare(cTable[i]->m_cnd->m_id->m_id.s) == 0)
		{
			mds = cTable[i]->m_mds;
			break;
		}
	}
	MethodDecls *pre,*next,*head;
	Id *id = new Id(*(mds->m_md->m_id));
	pre = new MethodDecls();
	pre->m_md = mds->m_md;
	pre->m_md->m_id = id;
	head = pre;
	mds = mds->m_mds;
	while(mds)
	{
		id = new Id(*(mds->m_md->m_id));
		next = new MethodDecls();
		next->m_md = mds->m_md;
		next->m_md->m_id = id;
		pre->m_mds = next;
		pre = next;

		mds = mds->m_mds;
	}
	pre->m_mds = NULL;
	return head;
}

int exists_varid(VarDecls *vd,string name)
{
	while(vd)
	{
		if(name.compare(vd->m_vd->m_id->m_id.s) == 0)
			return 1;
		vd = vd->m_vds;
	}

	return 0;
}

int exists_methodid(MethodDecls *md,string name)
{
	while(md)
	{
		if(name.compare(md->m_md->m_id->m_id.s) == 0)
			return 1;
		md = md->m_mds;
	}
	return 0;
}

void insert_var_methods(ClassDecl *cd,VarDecls *pvars,MethodDecls *pmethods,string pName)
{
	VarDecls *currvar = pvars;
	MethodDecls *currmethod = pmethods;
	while(currvar)
	{
		if(exists_varid(cd->m_vds,currvar->m_vd->m_id->m_id.s))
		{
			currvar->m_vd->m_id->m_id.s = pName + "_" + currvar->m_vd->m_id->m_id.s;
						//遇到父类中有与子类相同的成员， 重命名父类中成员，加前缀“父类名_”
		}
		currvar = currvar->m_vds;
	}
	while(currmethod)
	{
		if(exists_methodid(cd->m_mds,currmethod->m_md->m_id->m_id.s))
		{
			currmethod->m_md->m_id->m_id.s = pName + "_" + currmethod->m_md->m_id->m_id.s;
						//遇到父类中有与子类相同的方法，重命名父类中方法，加前缀“父类名_”
		}
		currmethod = currmethod->m_mds;
	}
	VarDecls *vars = cd->m_vds;
	MethodDecls *methods = cd->m_mds;
	while(vars->m_vds)
	{
		vars = vars->m_vds;
	}
	vars->m_vds = pvars;
	while(methods->m_mds)
	{
		methods = methods->m_mds;
	}
	methods->m_mds = pmethods;

}

int elimate_extends(Program *p)
{
	int i = 0;
	ClassDecls *cds = p->m_clsdcls;
	cTable[index++] = cds->m_clsdcl;
	cds = cds->m_clsdcls;
	ClassDecl *cd;
	while(cds)
	{
		cd = cds->m_clsdcl;

		std::cout<<"super class:"<<((ExtendsClassDecl*)cd)->m_pId->m_id.s<<std::endl;
		std::cout<<"derived class:"<<((ExtendsClassDecl*)cd)->m_cnd->m_id->m_id.s<<std::endl;
		std::cout<<"typeid: "<<typeid(*cd).name()<<std::endl;
		std::cout<<"expected typeid: "<<typeid(ExtendsClassDecl).name()<<std::endl;


		if(typeid(*cd).name() == typeid(ExtendsClassDecl).name())
		{
			string pName(((ExtendsClassDecl*)cd)->m_pId->m_id.s);

			VarDecls *pvars = get_vardecls(pName);   
			MethodDecls *pmethods = get_methoddecls(pName);
			insert_var_methods((ExtendsClassDecl*)cd,pvars,pmethods,pName);
		}
		cTable[index++] = cds->m_clsdcl;
		cds = cds->m_clsdcls;

	}
	

	
	return 0;
}