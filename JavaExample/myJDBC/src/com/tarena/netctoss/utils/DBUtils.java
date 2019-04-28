package com.tarena.netctoss.utils;

import java.sql.Connection;
import java.util.Properties;

import org.apache.commons.dbcp.BasicDataSource;

public class DBUtils {
	private static String driver;

	private static String url;

	private static String user;

	private static String password;

	private static BasicDataSource ds;

	private static ThreadLocal<Connection> tl = new ThreadLocal<Connection>();

	static {
		try {
			Properties props = new Properties();
			// 从类路径中加文件
			props.load(DBUtils.class.getClassLoader().getResourceAsStream(
					"com/tarena/netctoss/utils/db.properties"));

			driver = props.getProperty("driver");
			url = props.getProperty("url");
			user = props.getProperty("user");
			password = props.getProperty("password");

			ds = new BasicDataSource();
			ds.setDriverClassName(driver);
			ds.setUrl(url);
			ds.setUsername(user);
			ds.setPassword(password);

		} catch (Exception e) {
			e.printStackTrace();
			throw new RuntimeException(e);
		}
	}

	public static Connection getConnection() throws Exception {
		Connection con = tl.get();
		if (con == null) {
			con = ds.getConnection();
			tl.set(con);
		}
		return con;
	}

	public static void closeConnetion() throws Exception {
		Connection con = tl.get();
		if (con != null) {
			con.close();
			tl.set(null); // 取消当前线程绑定的连接
		}
	}
	

	public static void main(String[] args) throws Exception {
		Connection con = getConnection();
		System.out.println(con.getClass().getName());
	}
}
