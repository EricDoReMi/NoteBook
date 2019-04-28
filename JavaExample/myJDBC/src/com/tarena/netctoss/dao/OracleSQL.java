package com.tarena.netctoss.dao;

public interface OracleSQL {
	/*
	 * ACCOUNT SQL
	 */
	public static final String ACCOUNT_COLUMNS = "ID,LOGIN_NAME,LOGIN_PASSWD,STATUS,"
			+ "CREATE_DATE,PAUSE_DATE,CLOSE_DATE,REAL_NAME,IDCARD,BIRTHDATE,"
			+ "GENDER,OCCUPATION,TELEPHONE,EMAIL,MAILADDRESS,ZIPCODE,QQ";

	public static final String ACCOUNT_FIND_ALL = "select " + ACCOUNT_COLUMNS
			+ " from (select " + ACCOUNT_COLUMNS
			+ ",rownum num from ACCOUNT where rownum<?) where num>=?";

	public static final String ACCOUNT_SAVE = "insert into ACCOUNT("
			+ ACCOUNT_COLUMNS
			+ ") values (SEQ_ACCOUNT.nextval,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";

	public static final String ACCOUNT_GET_TOTAL_ROWS = "select count(*) from ACCOUNT";

	public static final String ACCOUNT_FIND_BY_ID = "select " + ACCOUNT_COLUMNS
			+ " from ACCOUNT where ID=?";

	public static final String ACCOUNT_FIND_BY = "select " + ACCOUNT_COLUMNS
			+ " from  (select " + ACCOUNT_COLUMNS
			+ ",rownum num from ACCOUNT where (0=? or IDCARD like ?) "
			+ "and (0=? or REAL_NAME like ?) "
			+ "and (0=? or LOGIN_NAME like ?) "
			+ "and (0=? or STATUS=?) and rownum<?) where num>=?";

	public static final String ACCOUNT_UPDATE = "update ACCOUNT set LOGIN_NAME=?,LOGIN_PASSWD=?,STATUS=?,"
			+ "CREATE_DATE=?,PAUSE_DATE=?,CLOSE_DATE=?,REAL_NAME=?,IDCARD=?,BIRTHDATE=?,"
			+ "GENDER=?,OCCUPATION=?,TELEPHONE=?,EMAIL=?,MAILADDRESS=?,ZIPCODE=?,QQ=? where ID=?";

	public static final String ACCOUNT_UPDATE_STATUS = "update ACCOUNT set STATUS=? where ID=?";

	public static final String SERVICE_COLUMNS = "ID,ACCOUNT_ID,COST_ID,UNIX_HOST,OS_USERNAME,LOGIN_PASSWD,STATUS,CREATE_DATE,PAUSE_DATE,CLOSE_DATE,IDCARD,REAL_NAME,COST_NAME";

	public static final String SERVICE_FIND_BY_ACCOUNT_ID = "select "
			+ SERVICE_COLUMNS + " from V_SERVICE where ACCOUNT_ID=?";
}







