#ifndef _HEADER__H__
#define _HEADER__H__

//���������
typedef struct array_t {  //���������� ��� ������ ������������ ������    
	int elements_count;   //����� ��������� �������
	void **memory_ptr;    //������������ ������ �� ����������
} Array;

typedef struct person_id {
	int series;
	int number;
} Person_ID;

typedef struct students_t {
	Person_ID id;
	char* firstName;
	char* middleName;
	char* lastName;
	int rate;
	int yearofBirth;
} Student;

typedef struct lecturers_t {
	Person_ID id;
	char* firstName;
	char* middleName;
	char* lastName;
	unsigned short grade;
	int yearofBirth;
} Lecturer;

//�������� �������
void* array_alloc();

void* array_set(Array*, int);

void* lect_alloc();

void* stud_alloc();

void free_Lecturer(Array*);

void free_Student(Array*);

void free_concate(Array*, int, int);

void get_lect(Array*);

void get_stud(Array*);

void out(Array*, Array*);

void out_concate(Array*, int, int);

//�������� �������
void map(Array*, void* function(void*));

void where(Array*, int function(void*));

void* concat(Array*, Array*);

//������� ��� map
void* grade_change(Lecturer*);

void* No_Birthday_Stud(Student*);

// ������� ��� where
int age_sort_stud(Student*);

int grade_sort(Lecturer*);

//�������� �������
void Testing();

int test_concate(Array*, Array*);

int test_where_lect(Array*);

int test_where_stud(Array*);

int test_map_stud(Array*);

int test_map_lect(Array*);

#endif /* _HEADER__H__ */

