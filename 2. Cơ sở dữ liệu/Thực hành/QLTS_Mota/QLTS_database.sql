create database QLTS
go
use QLTS
go
-------CSDL : Quan ly thi tuyen sinh-------------

if exists( select * from sysobjects where name =N'fk_NK_NGANH')
	alter table NGANH_KHOI
		drop constraint fk_NK_NGANH

if exists( select * from sysobjects where name =N'fk_NK_KHOI')
	alter table NGANH_KHOI
		drop constraint fk_NK_KHOI

if exists( select * from sysobjects where name =N'fk_TS_NK')
	alter table THISINH
		drop constraint fk_TS_NK

if exists( select * from sysobjects where name =N'fk_DT_TS')
	alter table DUTHI
		drop constraint fk_DT_TS

if exists( select * from sysobjects where name =N'fk_DT_DDT')
	alter table DUTHI
		drop constraint fk_DT_DDT

if exists( select * from sysobjects where name =N'fk_DT_BT')
	alter table DUTHI
		drop constraint fk_DT_BT

if exists( select * from sysobjects where name =N'fk_BT_KM')
	alter table BUOITHI
		drop constraint fk_BT_KM

if exists( select * from sysobjects where name =N'fk_KM_KHOI')
	alter table KHOI_MON
		drop constraint fk_KM_KHOI

if exists( select * from sysobjects where name =N'fk_KM_MT')
	alter table KHOI_MON
		drop constraint fk_KM_MT


if exists( select * from sysobjects where name = N'THISINH')
	drop table  THISINH

if exists( select * from sysobjects where name = N'NGANH')
	drop table NGANH

if exists( select * from sysobjects where name = N'KHOI')
	drop table KHOI

if exists( select * from sysobjects where name = N'NGANH_KHOI')
	drop table NGANH_KHOI

if exists( select * from sysobjects where name = N'MONTHI')
	drop table MONTHI

if exists( select * from sysobjects where name = N'KHOI_MON')
	drop table KHOI_MON

if exists( select * from sysobjects where name = N'BUOITHI')
	drop table BUOITHI

if exists( select * from sysobjects where name = N'DIADIEMTHI')
	drop table DIADIEMTHI

if exists( select * from sysobjects where name = N'DUTHI')
	drop table DUTHI



-------PHAN TAO BANG----------------------------------

create table THISINH
(
  SBD		char(11)	not null,
  HoTen		nvarchar(50)	not null,
  NgaySinh	datetime	not null,
  HoKhau	nvarchar(50)	null,			
  NoiHocPTTH	nvarchar(50)	null,
  Nganh		char(3)		null,
  Khoi		char(2)		null,
  constraint  pk_TS	primary key(SBD)
)

---------------------------------------

create table NGANH
(
  MaNganh	char(3)		not null,
  TenNganh	nvarchar(30)	null,
  ChiTieu	int		null,
  constraint pk_Nganh	primary key(MaNganh)	
)

----------------------------------------------------
create table KHOI
(
  MaKhoi	char(2)		not null,
  TenKhoi	nvarchar(10)	null,	
  constraint	pk_Khoi primary key (MaKhoi)
)

----------------------------------------------
create table NGANH_KHOI
(
  MaNganh	char(3)		not null,
  MaKhoi	char(2)		not null,
  DiemChuan	decimal(4,2)	null,	
  constraint pk_NK	primary key(MaNganh, MaKhoi)	
)

------------------------------------------
create table MONTHI
(
  MaMT		char(3),
  TenMT		nvarchar(30),
  constraint  pk_MT primary key(MaMT)
)
------------------------------------------
create table KHOI_MON	
(
  MaKhoi	char(2)		not null,
  MaMon		char(3)		not null,
  TiLe		float		not null,
  constraint pk_KM primary key(MaKhoi, MaMon)
)
------------------------------------------
create table BUOITHI
(
  MaBT		char(5)		not null,
  MaMon		char(3)		not null,
  MaKhoi	char(2)		not null,
  TDBatDau	datetime	null,
  ThoiGianThi	int		null,
  constraint	pk_BT primary key(MaBT),
  constraint 	u_BT  unique(MaKhoi,MaMon)	
)

-----------------------------------------
create table DIADIEMTHI
(
   MaDDT	char(5)		not null,
   TenDDT	nvarchar(30)	null,
   DiaChi	nvarchar(50)	null,
   constraint   pk_DDT 	primary key(MaDDT)	
)

-----------------------------------
create table DUTHI
(
   SBD		char(11)	not null,
   MaBT		char(5)		not null,
   DiaDiemThi	char(5)		null,
   Phong	char(3)		null,
   Diem		decimal(4,2)	null,   			  	
   constraint pk_DT primary key(SBD, MaBT)	
)

/*=============================================================*/
/*===TAO KHOA NGOAI============================================*/
/*=============================================================*/
alter table NGANH_KHOI
	add constraint fk_NK_NGANH foreign key( MaNganh )
	references NGANH(MaNganh)


alter table NGANH_KHOI
	add constraint fk_NK_KHOI foreign key ( MaKhoi)
	references KHOI(MaKhoi)
-----------------------------------------------------------

alter table THISINH
	add constraint fk_TS_NK foreign key (Nganh, Khoi)
 	references NGANH_KHOI (MaNganh, MaKhoi)
-----------------------------------------------------------

alter table DUTHI
	add constraint fk_DT_TS foreign key (SBD)
	references THISINH(SBD)


alter table DUTHI
	add constraint fk_DT_DDT foreign key (DiaDiemThi)
	references DIADIEMTHI( MaDDT)

alter table DUTHI
	add constraint fk_DT_BT foreign key (MaBT)
	references BUOITHI(MaBT)
---------------------------------------------------------

alter table BUOITHI
	add constraint fk_BT_KM foreign key (MaKhoi,MaMon)
	references KHOI_MON (MaKhoi, MaMon)
--------------------------------------------------------
alter table KHOI_MON
	add constraint fk_KM_KHOI foreign key (MaKhoi)
	references KHOI(MaKhoi)

alter table KHOI_MON
	add constraint fk_KM_MT foreign key (MaMon)
	references MONTHI(MaMT)


/*===============Nhap lieu====================================================*/
--bang NGANH
insert into NGANH(MaNganh, TenNganh, ChiTieu)
values('101','Toan - Tin hoc',300)

insert into NGANH(MaNganh, TenNganh, ChiTieu)
values('104','Vat ly',300)

insert into NGANH(MaNganh, TenNganh, ChiTieu)
values('107','Cong nghe Thong tin',480)

insert into NGANH(MaNganh, TenNganh, ChiTieu)
values('205','Khoa hoc Moi truong',150)

insert into NGANH(MaNganh, TenNganh, ChiTieu)
values('312','Cong nghe Sinh hoc',170)

go
-----bang KHOI
insert into KHOI(MaKhoi, TenKhoi)
values('A','Khoi A')
insert into KHOI
values('B','Khoi B')
go

----bang NGANH_KHOI
insert into NGANH_KHOI(MaNganh, MaKhoi,DiemChuan)
values('101','A',17.5)

insert into NGANH_KHOI(MaNganh, MaKhoi,DiemChuan)
values('104','A',15)

insert into NGANH_KHOI(MaNganh, MaKhoi,DiemChuan)
values('107','A',21)

insert into NGANH_KHOI(MaNganh, MaKhoi,DiemChuan)
values('205','A',18)

insert into NGANH_KHOI(MaNganh, MaKhoi,DiemChuan)
values('205','B',22.5)

insert into NGANH_KHOI(MaNganh, MaKhoi,DiemChuan)
values('312','A',21)

insert into NGANH_KHOI(MaNganh, MaKhoi,DiemChuan)
values('312','B',24.5)

go

---bang MONTHI
insert into MONTHI(MaMT, TenMT)
values('T','Toan')

insert into MONTHI(MaMT, TenMT)
values('L','Vat Ly')

insert into MONTHI(MaMT, TenMT)
values('H','Hoa Hoc')

insert into MONTHI(MaMT, TenMT)
values('S','Sinh Hoc')

---bang KHOI_MON
insert into KHOI_MON(MaKhoi, MaMon, TiLe)
values('A','T', 2)
insert into KHOI_MON(MaKhoi, MaMon, TiLe)
values('A','L', 1.5)
insert into KHOI_MON(MaKhoi, MaMon, TiLe)
values('A','H', 1)
insert into KHOI_MON(MaKhoi, MaMon, TiLe)

values('B','T', 1)
insert into KHOI_MON(MaKhoi, MaMon, TiLe)
values('B','H', 1.5)
insert into KHOI_MON(MaKhoi, MaMon, TiLe)
values('B','S', 2)


-- bang THISINH
--nganh 101, khoi A
insert into THISINH(SBD,HoTen,NgaySinh,HoKhau,NoiHocPTTH,Nganh,Khoi)
values('QST.A.00075','La Kim Anh','03/29/1985','Quan 5 - TP HCM','THPT Hung Vuong TPHCM','101','A')

insert into THISINH(SBD,HoTen,NgaySinh,HoKhau,NoiHocPTTH,Nganh,Khoi)
values('QST.A.01395','Le Huynh Giang','10/01/1985','TX Tan An - Tinh Long An ','THPT Tan An, Tinh Long An','101','A')

-- nganh 104, khoi A
insert into THISINH(SBD,HoTen,NgaySinh,HoKhau,NoiHocPTTH,Nganh,Khoi)
values('QST.A.01107','Pham Minh Duy','08/16/1986','H Tan Thanh - Tinh Ba Ria-VT','THPT Phu My, Tinh Ba Ria-VT','104','A')

insert into THISINH(SBD,HoTen,NgaySinh,HoKhau,NoiHocPTTH,Nganh,Khoi)
values('QST.A.06463','Pham Quoc Vinh','01/01/1983','H Thanh Phu - Tinh Ben Tre','THPT Thanh Phu, Tinh Ben Tre','104','A')

--nganh 107, khoi A
insert into THISINH(SBD,HoTen,NgaySinh,HoKhau,NoiHocPTTH,Nganh,Khoi)
values('QST.A.03709','Pham Thi Hong Nhung','12/08/1984','H Thanh Phu - Tinh Ben Tre','THPT Tam Phuoc, Tinh Dong Nai','107','A')

insert into THISINH(SBD,HoTen,NgaySinh,HoKhau,NoiHocPTTH,Nganh,Khoi)
values('QST.A.00779','Le Minh Cuong','01/02/1986','Quan 10 - TP HCM','THPT Le Hong Phong,TP HCM','107','A')

--nganh 205, khoi A

insert into THISINH(SBD,HoTen,NgaySinh,HoKhau,NoiHocPTTH,Nganh,Khoi)
values('QST.A.12454','Dang Thi Thuy Vy','01/08/1983','Quan Ninh Kieu- TP Can Tho','THPT BC Ng Viet Dung, TP Can Tho','205','A')

insert into THISINH(SBD,HoTen,NgaySinh,HoKhau,NoiHocPTTH,Nganh,Khoi)
values('QST.A.01215','Nguyen Duy Dat','01/20/1985','Quan Binh Thanh- TP HCM','THPT Ngo Quyen, Tinh Dong Nai','205','A')
 
--nganh 205, khoi B
insert into THISINH(SBD,HoTen,NgaySinh,HoKhau,NoiHocPTTH,Nganh,Khoi)
values('QST.B.00024','Nguyen Thi Thuy An','03/07/1986','Quan Binh Thanh- TP HCM','THPT Gia Dinh, TP HCM','205','B')
insert into THISINH(SBD,HoTen,NgaySinh,HoKhau,NoiHocPTTH,Nganh,Khoi)
values('QST.B.00627','Le Bao Chau','09/24/1986','Quan 1- TP HCM','THPT Bui Thi Xuan, TP HCM','205','B')

--nganh 312, khoi A
insert into THISINH(SBD,HoTen,NgaySinh,HoKhau,NoiHocPTTH,Nganh,Khoi)
values('QST.A.06715','Phan Thanh Duy','11/20/1986','H Long Ho - Tinh Vinh Long','THPT chuyen NBK, tinh Vinh Long','312','A')

insert into THISINH(SBD,HoTen,NgaySinh,HoKhau,NoiHocPTTH,Nganh,Khoi)
values('QST.A.06765','Pham Thi My Hanh','04/18/1985','H Cang Long - Tinh Tra Vinh','THPT DTNT Tra Vinh, tinh Tra Vinh','312','A')

--nganh 312, khoi B
insert into THISINH(SBD,HoTen,NgaySinh,HoKhau,NoiHocPTTH,Nganh,Khoi)
values('QST.B.04729','Phan Van Thanh','11/09/1982','H Can Gio - TP HCM','THPT Binh Khanh, TP HCM','312','B')
insert into THISINH(SBD,HoTen,NgaySinh,HoKhau,NoiHocPTTH,Nganh,Khoi)
values('QST.B.08864','Vo Thi Thanh Hang','12/31/1986','Q Son Tra - TP Da Nang','THPT Hoang Hoa Tham, TP Da Nang','312','B')

--bang DIADIEMTHI
insert into DIADIEMTHI(MaDDT,TenDDT,DiaChi)
values('H001','Truong DH KHTN','227 Nguyen Van Cu, Q5, TP HCM')
insert into DIADIEMTHI(MaDDT,TenDDT,DiaChi)
values('H002','Truong THCS BC Bach Dang','386/42 Le Van Si, Q3, TP HCM')
insert into DIADIEMTHI(MaDDT,TenDDT,DiaChi)
values('C001','Truong THPT Bui Huu Nghia','55 CMT8, Q Binh Thuy, TP Can Tho')
insert into DIADIEMTHI(MaDDT,TenDDT,DiaChi)
values('B001','Truong CDSP Binh Dinh','130 Tran Hung Dao, TP Qui Nhon, tinh Binh Dinh')

--bang BUOI THI
insert into BUOITHI(MaBT,MaMon,MaKhoi,TDBatDau,ThoiGianThi)
values('0401','T','A','07/05/2004 8:00:00',180)

insert into BUOITHI(MaBT,MaMon,MaKhoi,TDBatDau,ThoiGianThi)
values('0402','L','A','07/05/2004 13:30:00',180)

insert into BUOITHI(MaBT,MaMon,MaKhoi,TDBatDau,ThoiGianThi)
values('0403','H','A','07/06/2004 8:00:00',180)

insert into BUOITHI(MaBT,MaMon,MaKhoi,TDBatDau,ThoiGianThi)
values('0404','T','B','07/10/2004 8:00:00',180)

insert into BUOITHI(MaBT,MaMon,MaKhoi,TDBatDau,ThoiGianThi)
values('0405','H','B','07/10/2004 13:30:00',180)

insert into BUOITHI(MaBT,MaMon,MaKhoi,TDBatDau,ThoiGianThi)
values('0406','S','B','07/11/2004 13:30:00',180)

--bang DUTHI
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.00075','0401','H001','001',6.5)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.00075','0402','H001','001',7)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.00075','0403','H001','001',4.5)

insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.00779','0401','H001','056',8.5)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.00779','0402','H001','056',7)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.00779','0403','H001','056',9)

insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.01107','0401','H002','017',3.5)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.01107','0402','H002','017',5)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.01107','0403','H002','017',5.5)

insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.01215','0401','H002','018',7.5)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.01215','0402','H002','018',8)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.01215','0403','H002','018',5.5)

insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.01395','0401','C001','008',9)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.01395','0402','C001','008',8)

insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.03709','0401','C001','048',9)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.03709','0402','C001','048',6)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.03709','0403','C001','048',10)

/*insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.06463','0401','C001','217',4.5)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.06463','0402','C001','217',3.5)*/

insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.06715','0401','C001','217',1.5)

insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.06765','0401','C001','017',5.5)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.06765','0402','C001','017',4.5)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.06765','0403','C001','017',7)

insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.12454','0401','C001','343',8)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.12454','0402','C001','343',5)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.A.12454','0403','C001','343',9)

insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.B.00024','0404','H002','027',9)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.B.00024','0405','H002','027',9.5)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.B.00024','0406','H002','027',8)

insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.B.00627','0404','H001','056',3.5)


insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.B.04729','0404','H002','007',6)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.B.04729','0405','H002','007',4)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.B.04729','0406','H002','007',7)

insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.B.08864','0404','B001','002',9)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.B.08864','0405','B001','002',10)
insert into DUTHI(SBD,MaBT,DiaDiemthi,Phong,Diem)
values('QST.B.08864','0406','B001','002',10)

use QLTS
go
--Cau phu
ALTER TABLE THISINH
ADD TongDiem float

ALTER TABLE THISINH
ADD KetQua nvarchar(20)

--Cau 1
SELECT DDT.TenDDT, DDT.DiaChi
FROM DIADIEMTHI DDT
WHERE DDT.DiaChi LIKE '%TP Can Tho%'
AND NOT EXISTS (
	SELECT KM.MaMon
	FROM KHOI_MON KM
	WHERE KM.MaKhoi = 'A'
	EXCEPT
	SELECT BT.MaMon
	FROM DUTHI DT
	JOIN BUOITHI BT ON DT.MaBT = BT.MaBT
	WHERE DDT.MaDDT = DT.DiaDiemThi
)
go
--Cau 2
SELECT BT.MaMon, BT.MaKhoi, TS.SBD, TS.HoTen, DT.Diem
FROM DUTHI DT
JOIN BUOITHI BT ON DT.MaBT = BT.MaBT
JOIN THISINH TS ON DT.SBD = TS.SBD
WHERE DT.Diem >= ALL (
	SELECT DT2.Diem
	FROM DUTHI DT2
	JOIN BUOITHI BT2 ON DT2.MaBT = BT2.MaBT
	JOIN THISINH TS2 ON DT2.SBD = TS2.SBD
	WHERE BT2.MaKhoi = BT.MaKhoi AND BT2.MaMon = BT.MaMon)
go
--Cau 3
CREATE PROC usp_TinhTongDiem 
@sbd char(11), @tongdiem float out
AS
	IF NOT EXISTS (SELECT * FROM THISINH WHERE SBD = @sbd)
	BEGIN
		print 'Ko ton tai sbd'
		return 0
	END

	SELECT @tongdiem = sum(DT.DIEM *km.Tile)*10
	FROM DUTHI DT
	JOIN BUOITHI BT ON DT.MaBT = BT.MaBT
	JOIN KHOI_MON KM ON BT.MaKhoi = KM.MaKhoi AND BT.MaMon = KM.MaMon
	WHERE DT.SBD = @sbd
	return 1
go

declare @tongdiem float
exec usp_TinhTongDiem 'QST.A.00075', @tongdiem out
print @tongdiem
go

--Cau 4
CREATE PROC usp_XetKetQuaThi
@SBD char(11)
AS
	IF NOT EXISTS (SELECT * FROM THISINH WHERE SBD = @sbd)
	BEGIN
		print 'Ko ton tai sbd'
		return 0
	END

	DECLARE @tongdiem float, @ketqua char(20), @diemchuan float
	IF ((SELECT COUNT(MaBT)
		FROM DUTHI DT
		WHERE DT.SBD = @SBD) < 2)
	BEGIN
		SET @tongdiem = NULL
		set @ketqua = 'Khong xet'
	END
	ELSE
	BEGIN
		EXEC usp_TinhTongDiem @sbd, @tongdiem out
		set @diemchuan = (SELECT DiemChuan	
						FROM THISINH TS
						JOIN NGANH_KHOI NK ON TS.Nganh = NK.MaNganh AND TS.Khoi = NK.MaKhoi
						WHERE TS.SBD = @SBD)
	END
	IF @tongdiem > @diemchuan
		SET @ketqua = 'Vuot chuan'
	ELSE
		SET @ketqua = 'Khong xet'
	UPDATE THISINH SET KetQua = @ketqua, TongDiem = @tongdiem WHERE SBD = @SBD
GO
EXEC usp_XetKetQuaThi 'QST.A.00779'
go

--Cau 5
CREATE PROC usp_XetKQThiALL
AS
	DECLARE cur cursor for select SBD from THISINH
	DECLARE @sbd char(11)

	open cur
	fetch next from cur into @sbd
	while (@@FETCH_STATUS = 0)
	begin
		exec usp_XetKetQuaThi @sbd
		fetch next from cur into @sbd
	end
	close cur
	deallocate cur
go
EXEC usp_XetKQThiALL



























