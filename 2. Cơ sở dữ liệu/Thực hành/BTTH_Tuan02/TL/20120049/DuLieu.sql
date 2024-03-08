USE [QLLopHoc]
GO
INSERT [dbo].[GIAOVIEN] ([magv], [hoten], [gioitinh], [ngaysinh], [diachi]) VALUES (N'00001', N'Nguyen Van A                  ', N'Nam  ', CAST(N'1990-01-01' AS Date), N'01A                                               ')
INSERT [dbo].[GIAOVIEN] ([magv], [hoten], [gioitinh], [ngaysinh], [diachi]) VALUES (N'00002', N'Nguyen Van B                  ', N'Nu   ', CAST(N'1990-01-02' AS Date), N'01B                                               ')
INSERT [dbo].[GIAOVIEN] ([magv], [hoten], [gioitinh], [ngaysinh], [diachi]) VALUES (N'00003', N'Nguyen Van C                  ', N'Nam  ', CAST(N'1990-01-03' AS Date), N'01C                                               ')
INSERT [dbo].[GIAOVIEN] ([magv], [hoten], [gioitinh], [ngaysinh], [diachi]) VALUES (N'00004', N'Nguyen Van D                  ', N'Nu   ', CAST(N'1990-01-04' AS Date), N'01D                                               ')
INSERT [dbo].[GIAOVIEN] ([magv], [hoten], [gioitinh], [ngaysinh], [diachi]) VALUES (N'00005', N'Nguyen Van E                  ', N'Nam  ', CAST(N'1990-01-05' AS Date), N'01E                                               ')
GO
INSERT [dbo].[HOCSINH] ([mahs], [hoten], [gioitinh], [ngaysinh], [diachi], [malop]) VALUES (N'20120001', N'Nguyen Thi A                  ', N'Nam', CAST(N'2002-01-01' AS Date), N'02A                                               ', N'20CTT1')
INSERT [dbo].[HOCSINH] ([mahs], [hoten], [gioitinh], [ngaysinh], [diachi], [malop]) VALUES (N'20120002', N'Nguyen Thi B                  ', N'Nu ', CAST(N'2002-01-02' AS Date), N'02B                                               ', N'20CTT1')
INSERT [dbo].[HOCSINH] ([mahs], [hoten], [gioitinh], [ngaysinh], [diachi], [malop]) VALUES (N'20120003', N'Nguyen Thi C                  ', N'Nam', CAST(N'2002-01-03' AS Date), N'02C                                               ', N'20CTT2')
INSERT [dbo].[HOCSINH] ([mahs], [hoten], [gioitinh], [ngaysinh], [diachi], [malop]) VALUES (N'20120004', N'Nguyen Thi D                  ', N'Nu ', CAST(N'2002-01-04' AS Date), N'02D                                               ', N'20CTT3')
INSERT [dbo].[HOCSINH] ([mahs], [hoten], [gioitinh], [ngaysinh], [diachi], [malop]) VALUES (N'20120005', N'Nguyen Thi E                  ', N'Nam', CAST(N'2002-01-05' AS Date), N'02E                                               ', N'20CTT4')
INSERT [dbo].[HOCSINH] ([mahs], [hoten], [gioitinh], [ngaysinh], [diachi], [malop]) VALUES (N'20120006', N'Nguyen Thi F                  ', N'Nu ', CAST(N'2002-01-06' AS Date), N'02F                                               ', N'20CTT5')
GO
INSERT [dbo].[LOPHOC] ([malop], [tenlop], [nam], [gvcn], [lop_tr]) VALUES (N'20CTT1', N'20CNTT1   ', N'2020', N'00001', N'20120001')
INSERT [dbo].[LOPHOC] ([malop], [tenlop], [nam], [gvcn], [lop_tr]) VALUES (N'20CTT2', N'20CNTT2   ', N'2020', N'00002', N'20120003')
INSERT [dbo].[LOPHOC] ([malop], [tenlop], [nam], [gvcn], [lop_tr]) VALUES (N'20CTT3', N'20CNTT3   ', N'2020', N'00003', N'20120004')
INSERT [dbo].[LOPHOC] ([malop], [tenlop], [nam], [gvcn], [lop_tr]) VALUES (N'20CTT4', N'20CNTT4   ', N'2020', N'00004', N'20120005')
INSERT [dbo].[LOPHOC] ([malop], [tenlop], [nam], [gvcn], [lop_tr]) VALUES (N'20CTT5', N'20CNTT5   ', N'2020', N'00005', N'20120006')
GO
