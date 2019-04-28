package com.tarena.netctoss.entity;

import java.sql.Date;

public class Account {

	private Integer id;

	private String loginName;

	private String loginPasswd;

	private String status;

	private Date createDate;

	private Date pauseDate;

	private Date closeDate;

	private String realName;

	private String idcard;

	private Date birthdate;

	private String gender;

	private String occupation;

	private String telephone;

	private String email;

	private String mailaddress;

	private String zipcode;

	private String qq;

	public Object[] toArray() {
		return new Object[] {loginName, loginPasswd, status, createDate,
				pauseDate, closeDate, realName, idcard, birthdate, gender, occupation,
				telephone, email, mailaddress, zipcode, qq};
	}

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public String getLoginName() {
		return loginName;
	}

	public void setLoginName(String loginName) {
		this.loginName = loginName;
	}

	public String getLoginPasswd() {
		return loginPasswd;
	}

	public void setLoginPasswd(String loginPasswd) {
		this.loginPasswd = loginPasswd;
	}

	public String getStatus() {
		return status;
	}

	public void setStatus(String status) {
		this.status = status;
	}

	public Date getCreateDate() {
		return createDate;
	}

	public void setCreateDate(Date createDate) {
		this.createDate = createDate;
	}

	public Date getPauseDate() {
		return pauseDate;
	}

	public void setPauseDate(Date pauseDate) {
		this.pauseDate = pauseDate;
	}

	public Date getCloseDate() {
		return closeDate;
	}

	public void setCloseDate(Date closeDate) {
		this.closeDate = closeDate;
	}

	public String getRealName() {
		return realName;
	}

	public void setRealName(String realName) {
		this.realName = realName;
	}

	public String getIdcard() {
		return idcard;
	}

	public void setIdcard(String idcard) {
		this.idcard = idcard;
	}

	public Date getBirthdate() {
		return birthdate;
	}

	public void setBirthdate(Date birthdate) {
		this.birthdate = birthdate;
	}

	public String getGender() {
		return gender;
	}

	public void setGender(String gender) {
		this.gender = gender;
	}

	public String getOccupation() {
		return occupation;
	}

	public void setOccupation(String occupation) {
		this.occupation = occupation;
	}

	public String getTelephone() {
		return telephone;
	}

	public void setTelephone(String telephone) {
		this.telephone = telephone;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getMailaddress() {
		return mailaddress;
	}

	public void setMailaddress(String mailaddress) {
		this.mailaddress = mailaddress;
	}

	public String getZipcode() {
		return zipcode;
	}

	public void setZipcode(String zipcode) {
		this.zipcode = zipcode;
	}

	public String getQq() {
		return qq;
	}

	public void setQq(String qq) {
		this.qq = qq;
	}

	@Override
	public String toString() {
		return "Account [id=" + id + ", loginName=" + loginName + ", loginPasswd="
				+ loginPasswd + ", status=" + status + ", createDate=" + createDate
				+ ", pauseDate=" + pauseDate + ", closeDate=" + closeDate
				+ ", realName=" + realName + ", idcard=" + idcard + ", birthdate="
				+ birthdate + ", gender=" + gender + ", occupation=" + occupation
				+ ", telephone=" + telephone + ", email=" + email + ", mailaddress="
				+ mailaddress + ", zipcode=" + zipcode + ", qq=" + qq + "]";
	}
}